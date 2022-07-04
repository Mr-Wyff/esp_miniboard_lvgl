/*
mode by xiaoxiaoyudu
github :https://github.com/xiaoxiaoyudu
qq :1907383069
blbl:两位真实好友
*/
#include "sntp_time.h"
#include "lvgl_gui.h"
static const char *TAG = "SNTP";

S_DATE_TIME_T s_date_time;

#ifdef CONFIG_SNTP_TIME_SYNC_METHOD_CUSTOM
void sntp_sync_time(struct timeval *tv)
{
    settimeofday(tv, NULL);
    ESP_LOGI(TAG, "Time is synchronized from custom code");
    sntp_set_sync_status(SNTP_SYNC_STATUS_COMPLETED);
}
#endif
void time_sync_notification_cb(struct timeval *tv)
{
    ESP_LOGI(TAG, "Notification of a time synchronization event");
}
void initialize_sntp(void)
{
    ESP_LOGI(TAG, "Initializing SNTP");
    sntp_setoperatingmode(SNTP_OPMODE_POLL);
    sntp_setservername(0, "ntp1.aliyun.com");
    sntp_setservername(1, "210.72.145.44"); // 国家授时中心服务器 IP 地址
    sntp_setservername(2, "1.cn.pool.ntp.org");
    sntp_set_time_sync_notification_cb(time_sync_notification_cb);
#ifdef CONFIG_SNTP_TIME_SYNC_METHOD_SMOOTH
    sntp_set_sync_mode(SNTP_SYNC_MODE_SMOOTH);
#endif
    sntp_init();
}
void time_init()
{

    time_t now;
    char strftime_buf[64];
    struct tm timeinfo;
    int retry = 0;

    time(&now);
    localtime_r(&now, &timeinfo);
    // Is time set? If not, tm_year will be (1970 - 1900).
    if (timeinfo.tm_year < (2016 - 1900))
    {
        ESP_LOGI(TAG, "Time is not set yet. Connecting to WiFi and getting time over NTP.");
        initialize_sntp();
        while (timeinfo.tm_year < (2019 - 1900))
        {
            ESP_LOGD(TAG, "Waiting for system time to be set... (%d)", ++retry);
            vTaskDelay(100 / portTICK_PERIOD_MS);
            time(&now);
            localtime_r(&now, &timeinfo);
        }
    }
    setenv("TZ", "UTC+8", 1);
    tzset();
    strftime(strftime_buf, sizeof(strftime_buf), "%c", &timeinfo);
    ESP_LOGI(TAG, "The current date/time in Shanghai is: %s", strftime_buf);
}

void get_time(struct tm *timeinfo)
{
    time_t now;
    //获取时间
    time(&now);
    // Set timezone to China Standard Time
    setenv("TZ", "CST-8", 1);
    tzset();
    localtime_r(&now, timeinfo);
}

void time_date_task(void *arg) //时间任务，一直在lvgl后台运行
{
    uint8_t time_cnt = 0;
    time_init();
    while (1)
    {
        get_time(&s_date_time.timeinfo_t); //获取时间

        if (time_cnt % 1 == 0)
        {
            printf("\r\ntime_hour is:%d\r\n", s_date_time.timeinfo_t.tm_hour);
            printf("\r\ntime_min is:%d\r\n", s_date_time.timeinfo_t.tm_min);
            printf("\r\ntime_sec is:%d\r\n", s_date_time.timeinfo_t.tm_sec);

            s_date_time.hour = s_date_time.timeinfo_t.tm_hour;
            s_date_time.min = s_date_time.timeinfo_t.tm_min;
            s_date_time.sec = s_date_time.timeinfo_t.tm_sec;
            time_cnt = 0;
        }
        time_cnt++;
        vTaskDelay(500 / portTICK_RATE_MS);

    }
}
