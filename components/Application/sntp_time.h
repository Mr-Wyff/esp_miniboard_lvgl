#ifndef _SNTP_TIME_
#define _SNTP_TIME_

/*******sntp********/
#include <time.h>
#include <sys/time.h>
#include "esp_attr.h"
#include "esp_sleep.h"
#include "esp_sntp.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_err.h"
#include "esp_log.h"
#include "esp_system.h"

typedef struct _DATE_TIME_T
{
    struct tm  timeinfo_t;
    int hour;
    int min;
    int sec;
} S_DATE_TIME_T;


void initialize_sntp(void);
void time_init();
void get_time(struct tm *timeinfo);
void time_date_task(void *arg);//时间任务，一直在lvgl后台运行



#endif
