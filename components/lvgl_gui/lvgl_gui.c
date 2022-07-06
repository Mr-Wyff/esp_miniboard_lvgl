#include "lvgl_gui.h"
#include "sntp_time.h"
#include "lv_font.h"
#include "https.h"
extern S_DATE_TIME_T s_date_time;

void numtostring_convert(int16_t num, char *str)
{
    sprintf(str, "%02d", num);
}

void Home_Page_Create(void)
{

    lv_obj_t *bgk;

    bgk = lv_obj_create(lv_scr_act(), NULL);                                                  //创建对象
    lv_obj_clean_style_list(bgk, LV_OBJ_PART_MAIN);                                           //清空对象风格
    lv_obj_set_style_local_bg_opa(bgk, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, LV_OPA_100);       //设置颜色覆盖度100%，数值越低，颜色越透。
    lv_obj_set_style_local_bg_color(bgk, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, LV_COLOR_WHITE); //设置背景颜色为绿色

    //省去下方两行代码，默认是从0,0处开始绘制
    lv_obj_set_x(bgk, 0);           //设置X轴起点
    lv_obj_set_y(bgk, 0);           //设置Y轴起点
    lv_obj_set_size(bgk, 240, 240); //设置覆盖大小
}

void lv_font_test(void)
{
    lv_obj_t *font_label;
    lv_obj_t *font_label1;
    lv_obj_t *src = lv_scr_act();

    static lv_style_t font_style;
    lv_style_init(&font_style);
    lv_style_set_text_font(&font_style, LV_STATE_DEFAULT, &lv_font_montserrat_16);
    font_label = lv_label_create(src, NULL);
    lv_obj_add_style(font_label, LV_LABEL_PART_MAIN, &font_style);
    lv_label_set_text_static(font_label, LV_SYMBOL_AUDIO " audio");
    lv_obj_align(font_label, NULL, LV_ALIGN_CENTER, 0, 0);

    static lv_style_t font_style1;
    lv_style_init(&font_style1);
    lv_style_set_text_font(&font_style1, LV_STATE_DEFAULT, &lv_font_montserrat_48);
    font_label1 = lv_label_create(src, NULL);
    lv_obj_add_style(font_label1, LV_LABEL_PART_MAIN, &font_style1);
    lv_label_set_text_static(font_label1, LV_SYMBOL_VIDEO " video");
    lv_obj_align(font_label1, NULL, LV_ALIGN_CENTER, 0, 30);
}

#define time_label_y 80
#define datelabel_y 130

lv_obj_t *time_hour_label;
lv_obj_t *time_min_label;
lv_obj_t *time_sec_label;
lv_obj_t *date_label;
lv_obj_t *week_label;
lv_obj_t *time_symbol_label;
lv_obj_t *time_label;

void time_label_disp(int hour, int min, int sec, const char *symbol)
{
    char str[20] = {0};
    lv_obj_t *src = lv_scr_act();
    //文字样式
    static lv_style_t font_style;
    lv_style_init(&font_style);
    lv_style_set_text_color(&font_style, LV_STATE_DEFAULT, LV_COLOR_ORANGE);
    lv_style_set_text_font(&font_style, LV_STATE_DEFAULT, &user_fonts_youyuan_25);

    //时间标签
    time_label = lv_label_create(src, NULL);
    lv_obj_add_style(time_label, LV_LABEL_PART_MAIN, &font_style);

    sprintf(str, "%02d%s%02d%s%02d", hour, ":", min, ":", sec);
    lv_label_set_text(time_label, str);
    lv_obj_set_pos(time_label, 30, time_label_y);
    // //时间-小时标签
    // time_hour_label = lv_label_create(src, NULL);
    // lv_obj_add_style(time_hour_label, LV_LABEL_PART_MAIN, &font_style);

    //格式转换
    /*
    numtostring_convert(hour, str);
    lv_label_set_text(time_hour_label, str);
    lv_obj_set_pos(time_hour_label, 15, time_label_y);
    //时间-:标签
    time_symbol_label = lv_label_create(src, NULL);
    lv_obj_add_style(time_symbol_label, LV_LABEL_PART_MAIN, &font_style);
    lv_label_set_text(time_symbol_label, symbol);
    lv_obj_set_pos(time_symbol_label, 20 + 44 * 1 + 15, time_label_y);
    //时间-分钟标签
    time_min_label = lv_label_create(src, NULL);
    lv_obj_add_style(time_min_label, LV_LABEL_PART_MAIN, &font_style);
    //数据格式转换
    numtostring_convert(min, str);
    lv_label_set_text(time_min_label, str);
    lv_obj_set_pos(time_min_label, 20 + 30 * 2 + 3, time_label_y);
    //时间-:标签
    time_symbol_label = lv_label_create(src, NULL);
    lv_obj_add_style(time_symbol_label, LV_LABEL_PART_MAIN, &font_style);
    lv_label_set_text(time_symbol_label, symbol);
    lv_obj_set_pos(time_symbol_label, 20 + 42 * 3 + 8, time_label_y);
    //时间-秒标签
    time_sec_label = lv_label_create(src, NULL);
    lv_obj_add_style(time_sec_label, LV_LABEL_PART_MAIN, &font_style);

    //数据格式转化
    numtostring_convert(sec, str);

    lv_label_set_text(time_sec_label, str);
    lv_obj_set_pos(time_sec_label, 20 + 37 * 4, time_label_y);
*/
    //日期label
    static lv_style_t font_style2;
    lv_style_init(&font_style2);
    lv_style_set_text_color(&font_style2, LV_STATE_DEFAULT, LV_COLOR_ORANGE);
    lv_style_set_text_font(&font_style2, LV_STATE_DEFAULT, &user_fonts_youyuan_13);
    //日期-日期图标签
    date_label = lv_label_create(src, NULL);
    lv_obj_add_style(date_label, LV_LABEL_PART_MAIN, &font_style2);
    lv_label_set_text(date_label, "12月30号");
    lv_obj_set_pos(date_label, 15, datelabel_y);
    //日期-星期标签
    week_label = lv_label_create(src, NULL);
    lv_obj_add_style(week_label, LV_LABEL_PART_MAIN, &font_style2);
    lv_label_set_text(week_label, "周六");
    lv_obj_set_pos(week_label, 110, datelabel_y);
}

void time_date_update(int hour, int min, int sec, int mon, int monday, int weekday)
{
    char str[20] = {0};
    uint8_t str_len = 0;
    //时间小时显示-格式转换
    // numtostring_convert(hour, str);

    sprintf(str, "%02d%s%02d%s%02d", hour, ":", min, ":", sec);
    lv_label_set_text(time_label, str);
    lv_obj_set_pos(time_label, 30, time_label_y);
    //时间分钟显示    //数据格式转换
    // numtostring_convert(min, str);
    // lv_label_set_text(time_min_label, str);
    // lv_obj_set_pos(time_min_label, 20 + 30 * 2 + 13, time_label_y);
    // //时间秒显示    //数据格式转化
    // numtostring_convert(sec, str);
    // lv_label_set_text(time_sec_label, str);
    // lv_obj_set_pos(time_sec_label, 20 + 37 * 4, time_label_y);

    //日期-日期图标签
    sprintf((char *)str, "%d%s%d%s", mon + 1, "月", monday, "日");

    lv_label_set_text(date_label, str);
    lv_obj_set_pos(date_label, 15, datelabel_y);
    str_len = strlen(str);
    //日期-星期标签
    const char *wday[] = {"日", "一", "二", "三", "四", "五", "六"};
    sprintf((char *)str, "周%s", wday[weekday]);
    lv_label_set_text(week_label, str);
    lv_obj_set_pos(week_label, 10 + str_len * 10, datelabel_y);
}

void whether_img(const void *img_src, uint8_t pos_x, uint8_t pos_y)
{
    lv_obj_t *img1 = lv_img_create(lv_scr_act(), NULL);
    lv_img_set_src(img1, img_src);
    lv_obj_set_pos(img1, pos_x, pos_y);
}

void temperature_img(const void *img_src, uint8_t pos_x, uint8_t pos_y)
{
    char str[100] = {0};
    lv_obj_t *src = lv_scr_act();

    lv_obj_t *img1 = lv_img_create(lv_scr_act(), NULL);
    lv_img_set_src(img1, img_src);
    lv_obj_set_pos(img1, pos_x, pos_y);

    lv_obj_t *temperature_bar = lv_bar_create(lv_scr_act(), NULL);
    lv_obj_set_size(temperature_bar, 60, 10);
    lv_obj_set_pos(temperature_bar, 45, 170);
    lv_bar_set_anim_time(temperature_bar, 2000);
    lv_bar_set_range(temperature_bar, 0, 100);
    lv_bar_set_value(temperature_bar, 50, LV_ANIM_ON);
    //温度值
    lv_obj_t *temperature_label;
    static lv_style_t font_style;
    lv_style_init(&font_style);
    lv_style_set_text_color(&font_style, LV_STATE_DEFAULT, LV_COLOR_ORANGE);
    lv_style_set_text_font(&font_style, LV_STATE_DEFAULT, &user_fonts_symbol_10);

    temperature_label = lv_label_create(src, NULL);
    lv_obj_add_style(temperature_label, LV_LABEL_PART_MAIN, &font_style);
    numtostring_convert(59, str);
    lv_label_set_text(temperature_label, str);
    lv_obj_set_pos(temperature_label, 110, 165);

    lv_obj_t *temperaturesymbol_label;

    temperaturesymbol_label = lv_label_create(src, NULL);
    lv_obj_add_style(temperaturesymbol_label, LV_LABEL_PART_MAIN, &font_style);
    lv_label_set_text(temperaturesymbol_label, "℃");
    lv_obj_set_pos(temperaturesymbol_label, 135, 165);
}

void humidity_img(const void *img_src, uint8_t pos_x, uint8_t pos_y)
{
    lv_obj_t *img1 = lv_img_create(lv_scr_act(), NULL);
    lv_obj_t *src = lv_scr_act();

    lv_img_set_src(img1, img_src);
    lv_obj_set_pos(img1, pos_x, pos_y);

    //进度条样式
    lv_obj_t *humidity_bar = lv_bar_create(lv_scr_act(), NULL);
    lv_obj_set_size(humidity_bar, 60, 10);
    lv_obj_set_pos(humidity_bar, 45, 210);
    lv_bar_set_anim_time(humidity_bar, 2000);
    lv_bar_set_range(humidity_bar, 0, 100);
    lv_bar_set_value(humidity_bar, 50, LV_ANIM_ON);

    //湿度值
    lv_obj_t *humidity_label;
    static lv_style_t font_style;
    lv_style_init(&font_style);
    lv_style_set_text_color(&font_style, LV_STATE_DEFAULT, LV_COLOR_ORANGE);
    lv_style_set_text_font(&font_style, LV_STATE_DEFAULT, &user_fonts_symbol_10);

    humidity_label = lv_label_create(src, NULL);
    lv_obj_add_style(humidity_label, LV_LABEL_PART_MAIN, &font_style);
    lv_label_set_text(humidity_label, "59");
    lv_obj_set_pos(humidity_label, 110, 205);

    lv_obj_t *humiditysymbol_label;

    humiditysymbol_label = lv_label_create(src, NULL);
    lv_obj_add_style(humiditysymbol_label, LV_LABEL_PART_MAIN, &font_style);
    lv_label_set_text(humiditysymbol_label, "%");
    lv_obj_set_pos(humiditysymbol_label, 140, 205);
}

void logo_img(const void *img_src, uint8_t pos_x, uint8_t pos_y)
{
    lv_obj_t *img1 = lv_img_create(lv_scr_act(), NULL);
    lv_img_set_src(img1, img_src);
    lv_obj_set_pos(img1, pos_x, pos_y);
}

lv_obj_t *whethercity_label;
lv_obj_t *whether_label;
lv_obj_t *airquality_label;

void whether_message(void)
{
    lv_obj_t *src = lv_scr_act();

    static lv_style_t font_style;
    lv_style_init(&font_style);
    lv_style_set_text_color(&font_style, LV_STATE_DEFAULT, LV_COLOR_ORANGE);
    lv_style_set_text_font(&font_style, LV_STATE_DEFAULT, &user_fonts_songti_20);

    whethercity_label = lv_label_create(src, NULL);
    lv_obj_add_style(whethercity_label, LV_LABEL_PART_MAIN, &font_style);
    lv_label_set_text(whethercity_label, "上海");
    lv_obj_set_pos(whethercity_label, 15, 10);

    airquality_label = lv_label_create(src, NULL);
    lv_obj_add_style(airquality_label, LV_LABEL_PART_MAIN, &font_style);
    lv_label_set_text(airquality_label, "优");
    lv_obj_set_pos(airquality_label, 100, 10);

    static lv_style_t font_style2;
    lv_style_init(&font_style2);
    lv_style_set_text_color(&font_style2, LV_STATE_DEFAULT, LV_COLOR_ORANGE);
    lv_style_set_text_font(&font_style2, LV_STATE_DEFAULT, &user_fonts_songti_15);

    whether_label = lv_label_create(src, NULL);
    lv_obj_add_style(whether_label, LV_LABEL_PART_MAIN, &font_style2);
    lv_label_set_text(whether_label, "西南风2级");
    lv_obj_set_pos(whether_label, 15, 50);
}

void whether_message_update(char *city)
{
    lv_label_set_text(whethercity_label, city);
    lv_obj_set_pos(whethercity_label, 15, 10);
}

void Temper_Task_Function(lv_task_t *task)
{
    //你的代码
    time_date_update(s_date_time.timeinfo_t.tm_hour, s_date_time.timeinfo_t.tm_min, s_date_time.timeinfo_t.tm_sec, s_date_time.timeinfo_t.tm_mon, s_date_time.timeinfo_t.tm_mday, s_date_time.timeinfo_t.tm_wday);
    whether_message_update(results[0].location.name);
}

void lv_task_init()
{
    lv_task_create(Temper_Task_Function, 500, LV_TASK_PRIO_MID, 0);
}

void lvgl_gui_sample()
{
    Home_Page_Create();
    //默认显示，随便什么都可以
    time_label_disp(11, 53, 40, ":");
    whether_img(&cloudy, 150, 5);
    temperature_img(&temperature, 10, 155);
    humidity_img(&humidity, 15, 190);
    logo_img(&dabai, 160, 130);
    whether_message();

    lv_task_init();
}
