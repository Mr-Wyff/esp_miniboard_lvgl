/* LVGL Example project
 *
 * Basic project to test LVGL on ESP32 based projects.
 *
 * This example code is in the Public Domain (or CC0 licensed, at your option.)
 *
 * Unless required by applicable law or agreed to in writing, this
 * software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
 * CONDITIONS OF ANY KIND, either express or implied.
 */
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_freertos_hooks.h"
#include "freertos/semphr.h"
#include "esp_system.h"
#include "driver/gpio.h"

/* Littlevgl specific */
#ifdef LV_LVGL_H_INCLUDE_SIMPLE
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif

#include "lvgl_helpers.h"

#include "lv_sjpg.h"
#include "gui_guider.h"
#include "events_init.h"

#ifndef CONFIG_LV_TFT_DISPLAY_MONOCHROME
#if defined CONFIG_LV_USE_DEMO_WIDGETS
#include "lv_examples/src/lv_demo_widgets/lv_demo_widgets.h"
#elif defined CONFIG_LV_USE_DEMO_KEYPAD_AND_ENCODER
#include "lv_examples/src/lv_demo_keypad_encoder/lv_demo_keypad_encoder.h"
#elif defined CONFIG_LV_USE_DEMO_BENCHMARK
#include "lv_examples/src/lv_demo_benchmark/lv_demo_benchmark.h"
#elif defined CONFIG_LV_USE_DEMO_STRESS
#include "lv_examples/src/lv_demo_stress/lv_demo_stress.h"
#else
#error "No demo application selected."
#endif
#endif

/*********************
 *      DEFINES
 *********************/
#define TAG "demo"
#define LV_TICK_PERIOD_MS 1

/**********************
 *  STATIC PROTOTYPES
 **********************/
static void lv_tick_task(void *arg);
static void guiTask(void *pvParameter);
static void create_demo_application(void);
// void setup_scr_screen(lv_ui *ui)
// {

//     lv_style_t main_bgColor;


//     // Write codes screen
//      ui->screen = lv_obj_create(NULL, NULL);

//      // Write codes screen_img_1
//      ui->screen_img_1 = lv_img_create(ui->screen, NULL);

//      // Write style LV_IMG_PART_MAIN for screen_img_1
//      static lv_style_t style_screen_img_1_main;
//      lv_style_reset(&style_screen_img_1_main);

//     //Write style state: LV_STATE_DEFAULT for style_screen_img_1_main
//     lv_style_set_image_recolor(&style_screen_img_1_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
//     lv_style_set_image_recolor_opa(&style_screen_img_1_main, LV_STATE_DEFAULT, 0);
//     lv_style_set_image_opa(&style_screen_img_1_main, LV_STATE_DEFAULT, 255);
//     lv_obj_add_style(ui->screen_img_1, LV_IMG_PART_MAIN, &style_screen_img_1_main);
//     lv_obj_set_pos(ui->screen_img_1, 8, 8);
//     lv_obj_set_size(ui->screen_img_1, 240, 240);
//     lv_obj_set_click(ui->screen_img_1, true);
//     lv_img_set_src(ui->screen_img_1, &_mini_board_alpha_223x223);
//     lv_img_set_pivot(ui->screen_img_1, 0, 0);
//     lv_img_set_angle(ui->screen_img_1, 0);
// }

void setup_scr_screen(lv_ui *ui){

	//Write codes screen
	ui->screen = lv_obj_create(NULL, NULL);

	//Write codes screen_canvas_1
	ui->screen_canvas_1 = lv_canvas_create(ui->screen, NULL);

	//Write style LV_CANVAS_PART_MAIN for screen_canvas_1
	static lv_style_t style_screen_canvas_1_main;
	lv_style_reset(&style_screen_canvas_1_main);

	//Write style state: LV_STATE_DEFAULT for style_screen_canvas_1_main
	lv_style_set_image_recolor(&style_screen_canvas_1_main, LV_STATE_DEFAULT, lv_color_make(0xfc, 0xfc, 0xfc));
	lv_style_set_image_recolor_opa(&style_screen_canvas_1_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->screen_canvas_1, LV_CANVAS_PART_MAIN, &style_screen_canvas_1_main);
	lv_obj_set_pos(ui->screen_canvas_1, 0, 0);
	lv_obj_set_size(ui->screen_canvas_1, 240, 240);
	lv_color_t *buf_screen_canvas_1 = (lv_color_t*)lv_mem_alloc(240*240*4);
	lv_canvas_set_buffer(ui->screen_canvas_1, buf_screen_canvas_1, 240, 240, LV_IMG_CF_TRUE_COLOR);

	//Write codes screen_time_label
	ui->screen_time_label = lv_label_create(ui->screen, NULL);
	lv_label_set_text(ui->screen_time_label, "12:45");
	lv_label_set_long_mode(ui->screen_time_label, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->screen_time_label, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for screen_time_label
	static lv_style_t style_screen_time_label_main;
	lv_style_reset(&style_screen_time_label_main);

	//Write style state: LV_STATE_DEFAULT for style_screen_time_label_main
	lv_style_set_radius(&style_screen_time_label_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen_time_label_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen_time_label_main, LV_STATE_DEFAULT, lv_color_make(0xfc, 0xfc, 0xfc));
	lv_style_set_bg_grad_dir(&style_screen_time_label_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_time_label_main, LV_STATE_DEFAULT, 255);
	lv_style_set_text_color(&style_screen_time_label_main, LV_STATE_DEFAULT, lv_color_make(0xee, 0x9c, 0x3f));
	lv_style_set_text_font(&style_screen_time_label_main, LV_STATE_DEFAULT, &lv_font_montserratMedium_29);
	lv_style_set_text_letter_space(&style_screen_time_label_main, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_left(&style_screen_time_label_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_screen_time_label_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_screen_time_label_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_screen_time_label_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->screen_time_label, LV_LABEL_PART_MAIN, &style_screen_time_label_main);
	lv_obj_set_pos(ui->screen_time_label, 13, 40);
	lv_obj_set_size(ui->screen_time_label, 90, 0);

	//Write codes screen_whether_img
	ui->screen_whether_img = lv_img_create(ui->screen, NULL);

	//Write style LV_IMG_PART_MAIN for screen_whether_img
	static lv_style_t style_screen_whether_img_main;
	lv_style_reset(&style_screen_whether_img_main);

	//Write style state: LV_STATE_DEFAULT for style_screen_whether_img_main
	lv_style_set_image_recolor(&style_screen_whether_img_main, LV_STATE_DEFAULT, lv_color_make(0xdc, 0xdc, 0xdc));
	lv_style_set_image_recolor_opa(&style_screen_whether_img_main, LV_STATE_DEFAULT, 0);
	lv_style_set_image_opa(&style_screen_whether_img_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->screen_whether_img, LV_IMG_PART_MAIN, &style_screen_whether_img_main);
	lv_obj_set_pos(ui->screen_whether_img, 139, 19);
	lv_obj_set_size(ui->screen_whether_img, 89, 88);
	lv_obj_set_click(ui->screen_whether_img, true);
	lv_img_set_src(ui->screen_whether_img,&_cloud2_alpha_89x88);
	lv_img_set_pivot(ui->screen_whether_img, 0,0);
	lv_img_set_angle(ui->screen_whether_img, 0);

	//Write codes screen_temp_img
	ui->screen_temp_img = lv_img_create(ui->screen, NULL);

	//Write style LV_IMG_PART_MAIN for screen_temp_img
	static lv_style_t style_screen_temp_img_main;
	lv_style_reset(&style_screen_temp_img_main);

	//Write style state: LV_STATE_DEFAULT for style_screen_temp_img_main
	lv_style_set_image_recolor(&style_screen_temp_img_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_image_recolor_opa(&style_screen_temp_img_main, LV_STATE_DEFAULT, 0);
	lv_style_set_image_opa(&style_screen_temp_img_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->screen_temp_img, LV_IMG_PART_MAIN, &style_screen_temp_img_main);
	lv_obj_set_pos(ui->screen_temp_img, 5, 113);
	lv_obj_set_size(ui->screen_temp_img, 48, 55);
	lv_obj_set_click(ui->screen_temp_img, true);
	lv_img_set_src(ui->screen_temp_img,&_Pm3XE4eMqr_jpg_alpha_48x55);
	lv_img_set_pivot(ui->screen_temp_img, 0,0);
	lv_img_set_angle(ui->screen_temp_img, 0);

	//Write codes screen_city_label
	ui->screen_city_label = lv_label_create(ui->screen, NULL);
	//v_label_set_text(ui->screen_city_label, "北京多云");
    lv_label_set_text(ui->screen_city_label, "cloudy");
	lv_label_set_long_mode(ui->screen_city_label, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->screen_city_label, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for screen_city_label
	static lv_style_t style_screen_city_label_main;
	lv_style_reset(&style_screen_city_label_main);

	//Write style state: LV_STATE_DEFAULT for style_screen_city_label_main
	lv_style_set_radius(&style_screen_city_label_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen_city_label_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen_city_label_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen_city_label_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_city_label_main, LV_STATE_DEFAULT, 255);
	lv_style_set_text_color(&style_screen_city_label_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_screen_city_label_main, LV_STATE_DEFAULT, &lv_font_simsun_19);
	lv_style_set_text_letter_space(&style_screen_city_label_main, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_left(&style_screen_city_label_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_screen_city_label_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_screen_city_label_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_screen_city_label_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->screen_city_label, LV_LABEL_PART_MAIN, &style_screen_city_label_main);
	lv_obj_set_pos(ui->screen_city_label, 134, 88);
	lv_obj_set_size(ui->screen_city_label, 100, 0);

	//Write codes screen_hum_img
	ui->screen_hum_img = lv_img_create(ui->screen, NULL);

	//Write style LV_IMG_PART_MAIN for screen_hum_img
	static lv_style_t style_screen_hum_img_main;
	lv_style_reset(&style_screen_hum_img_main);

	//Write style state: LV_STATE_DEFAULT for style_screen_hum_img_main
	lv_style_set_image_recolor(&style_screen_hum_img_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_image_recolor_opa(&style_screen_hum_img_main, LV_STATE_DEFAULT, 0);
	lv_style_set_image_opa(&style_screen_hum_img_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->screen_hum_img, LV_IMG_PART_MAIN, &style_screen_hum_img_main);
	lv_obj_set_pos(ui->screen_hum_img, 4, 175);
	lv_obj_set_size(ui->screen_hum_img, 40, 55);
	lv_obj_set_click(ui->screen_hum_img, true);
	lv_img_set_src(ui->screen_hum_img,&_shidu_jpg_alpha_40x55);
	lv_img_set_pivot(ui->screen_hum_img, 0,0);
	lv_img_set_angle(ui->screen_hum_img, 0);

	//Write codes screen_temp_bar
	ui->screen_temp_bar = lv_bar_create(ui->screen, NULL);

	//Write style LV_BAR_PART_BG for screen_temp_bar
	static lv_style_t style_screen_temp_bar_bg;
	lv_style_reset(&style_screen_temp_bar_bg);

	//Write style state: LV_STATE_DEFAULT for style_screen_temp_bar_bg
	lv_style_set_radius(&style_screen_temp_bar_bg, LV_STATE_DEFAULT, 10);
	lv_style_set_bg_color(&style_screen_temp_bar_bg, LV_STATE_DEFAULT, lv_color_make(0xd4, 0xd7, 0xd9));
	lv_style_set_bg_grad_color(&style_screen_temp_bar_bg, LV_STATE_DEFAULT, lv_color_make(0xd4, 0xd7, 0xd9));
	lv_style_set_bg_grad_dir(&style_screen_temp_bar_bg, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_temp_bar_bg, LV_STATE_DEFAULT, 255);
	lv_style_set_pad_left(&style_screen_temp_bar_bg, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_screen_temp_bar_bg, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_screen_temp_bar_bg, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_screen_temp_bar_bg, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->screen_temp_bar, LV_BAR_PART_BG, &style_screen_temp_bar_bg);

	//Write style LV_BAR_PART_INDIC for screen_temp_bar
	static lv_style_t style_screen_temp_bar_indic;
	lv_style_reset(&style_screen_temp_bar_indic);

	//Write style state: LV_STATE_DEFAULT for style_screen_temp_bar_indic
	lv_style_set_radius(&style_screen_temp_bar_indic, LV_STATE_DEFAULT, 10);
	lv_style_set_bg_color(&style_screen_temp_bar_indic, LV_STATE_DEFAULT, lv_color_make(0x01, 0xa2, 0xb1));
	lv_style_set_bg_grad_color(&style_screen_temp_bar_indic, LV_STATE_DEFAULT, lv_color_make(0x01, 0xa2, 0xb1));
	lv_style_set_bg_grad_dir(&style_screen_temp_bar_indic, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_temp_bar_indic, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->screen_temp_bar, LV_BAR_PART_INDIC, &style_screen_temp_bar_indic);
	lv_obj_set_pos(ui->screen_temp_bar, 53, 137);
	lv_obj_set_size(ui->screen_temp_bar, 64, 11);
	lv_bar_set_anim_time(ui->screen_temp_bar,1000);
	lv_bar_set_value(ui->screen_temp_bar,50,LV_ANIM_OFF);
	lv_bar_set_range(ui->screen_temp_bar,0,100);

	//Write codes screen_date_label
	ui->screen_date_label = lv_label_create(ui->screen, NULL);
	// lv_label_set_text(ui->screen_date_label, "星期四 6/30");
    lv_label_set_text(ui->screen_date_label, "Thur 6/30");

	lv_label_set_long_mode(ui->screen_date_label, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->screen_date_label, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for screen_date_label
	static lv_style_t style_screen_date_label_main;
	lv_style_reset(&style_screen_date_label_main);

	//Write style state: LV_STATE_DEFAULT for style_screen_date_label_main
	lv_style_set_radius(&style_screen_date_label_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen_date_label_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen_date_label_main, LV_STATE_DEFAULT, lv_color_make(0xfc, 0xfc, 0xfc));
	lv_style_set_bg_grad_dir(&style_screen_date_label_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_date_label_main, LV_STATE_DEFAULT, 255);
	lv_style_set_text_color(&style_screen_date_label_main, LV_STATE_DEFAULT, lv_color_make(0xee, 0x9c, 0x3f));
	lv_style_set_text_font(&style_screen_date_label_main, LV_STATE_DEFAULT, &lv_font_montserratMedium_13);
	lv_style_set_text_letter_space(&style_screen_date_label_main, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_left(&style_screen_date_label_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_screen_date_label_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_screen_date_label_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_screen_date_label_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->screen_date_label, LV_LABEL_PART_MAIN, &style_screen_date_label_main);
	lv_obj_set_pos(ui->screen_date_label, 18, 76);
	lv_obj_set_size(ui->screen_date_label, 90, 0);

	//Write codes screen_hum_bar
	ui->screen_hum_bar = lv_bar_create(ui->screen, NULL);

	//Write style LV_BAR_PART_BG for screen_hum_bar
	static lv_style_t style_screen_hum_bar_bg;
	lv_style_reset(&style_screen_hum_bar_bg);

	//Write style state: LV_STATE_DEFAULT for style_screen_hum_bar_bg
	lv_style_set_radius(&style_screen_hum_bar_bg, LV_STATE_DEFAULT, 10);
	lv_style_set_bg_color(&style_screen_hum_bar_bg, LV_STATE_DEFAULT, lv_color_make(0xd4, 0xd7, 0xd9));
	lv_style_set_bg_grad_color(&style_screen_hum_bar_bg, LV_STATE_DEFAULT, lv_color_make(0xd4, 0xd7, 0xd9));
	lv_style_set_bg_grad_dir(&style_screen_hum_bar_bg, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_hum_bar_bg, LV_STATE_DEFAULT, 255);
	lv_style_set_pad_left(&style_screen_hum_bar_bg, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_screen_hum_bar_bg, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_screen_hum_bar_bg, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_screen_hum_bar_bg, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->screen_hum_bar, LV_BAR_PART_BG, &style_screen_hum_bar_bg);

	//Write style LV_BAR_PART_INDIC for screen_hum_bar
	static lv_style_t style_screen_hum_bar_indic;
	lv_style_reset(&style_screen_hum_bar_indic);

	//Write style state: LV_STATE_DEFAULT for style_screen_hum_bar_indic
	lv_style_set_radius(&style_screen_hum_bar_indic, LV_STATE_DEFAULT, 10);
	lv_style_set_bg_color(&style_screen_hum_bar_indic, LV_STATE_DEFAULT, lv_color_make(0x01, 0xa2, 0xb1));
	lv_style_set_bg_grad_color(&style_screen_hum_bar_indic, LV_STATE_DEFAULT, lv_color_make(0x01, 0xa2, 0xb1));
	lv_style_set_bg_grad_dir(&style_screen_hum_bar_indic, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_hum_bar_indic, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->screen_hum_bar, LV_BAR_PART_INDIC, &style_screen_hum_bar_indic);
	lv_obj_set_pos(ui->screen_hum_bar, 55, 196);
	lv_obj_set_size(ui->screen_hum_bar, 61, 12);
	lv_bar_set_anim_time(ui->screen_hum_bar,1000);
	lv_bar_set_value(ui->screen_hum_bar,50,LV_ANIM_OFF);
	lv_bar_set_range(ui->screen_hum_bar,0,100);

	//Write codes screen_logo_img
	ui->screen_logo_img = lv_img_create(ui->screen, NULL);

	//Write style LV_IMG_PART_MAIN for screen_logo_img
	static lv_style_t style_screen_logo_img_main;
	lv_style_reset(&style_screen_logo_img_main);

	//Write style state: LV_STATE_DEFAULT for style_screen_logo_img_main
	lv_style_set_image_recolor(&style_screen_logo_img_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_image_recolor_opa(&style_screen_logo_img_main, LV_STATE_DEFAULT, 0);
	lv_style_set_image_opa(&style_screen_logo_img_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->screen_logo_img, LV_IMG_PART_MAIN, &style_screen_logo_img_main);
	lv_obj_set_pos(ui->screen_logo_img, 132, 130);
	lv_obj_set_size(ui->screen_logo_img, 100, 100);
	lv_obj_set_click(ui->screen_logo_img, true);
	lv_img_set_src(ui->screen_logo_img,&_dabai_alpha_100x100);
	lv_img_set_pivot(ui->screen_logo_img, 0,0);
	lv_img_set_angle(ui->screen_logo_img, 0);
}
void Home_Page_Create(void)
{

    lv_obj_t* bgk;

    bgk = lv_obj_create(lv_scr_act(), NULL);//创建对象

    lv_obj_clean_style_list(bgk, LV_OBJ_PART_MAIN); //清空对象风格

    lv_obj_set_style_local_bg_opa(bgk, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, LV_OPA_100);//设置颜色覆盖度100%，数值越低，颜色越透。

    lv_obj_set_style_local_bg_color(bgk, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, LV_COLOR_BLUE);//设置背景颜色为绿色

    //省去下方两行代码，默认是从0,0处开始绘制

    lv_obj_set_x(bgk, 0);//设置X轴起点

    lv_obj_set_y(bgk, 0);//设置Y轴起点

    lv_obj_set_size(bgk, 240, 240);//设置覆盖大小

}
/**********************
 *   APPLICATION MAIN
 **********************/
void app_main()
{

    /* If you want to use a task to create the graphic, you NEED to create a Pinned task
     * Otherwise there can be problem such as memory corruption and so on.
     * NOTE: When not using Wi-Fi nor Bluetooth you can pin the guiTask to core 0 */
    xTaskCreatePinnedToCore(guiTask, "gui", 4096 * 2, NULL, 0, NULL, 1);
}

/* Creates a semaphore to handle concurrent call to lvgl stuff
 * If you wish to call *any* lvgl function from other threads/tasks
 * you should lock on the very same semaphore! */
SemaphoreHandle_t xGuiSemaphore;

static void guiTask(void *pvParameter)
{

    (void)pvParameter;
    xGuiSemaphore = xSemaphoreCreateMutex();

    lv_init();

    /* Initialize SPI or I2C bus used by the drivers */
    lvgl_driver_init();

    lv_color_t *buf1 = heap_caps_malloc(DISP_BUF_SIZE * sizeof(lv_color_t), MALLOC_CAP_DMA);
    assert(buf1 != NULL);

    /* Use double buffered when not working with monochrome displays */
#ifndef CONFIG_LV_TFT_DISPLAY_MONOCHROME
    lv_color_t *buf2 = heap_caps_malloc(DISP_BUF_SIZE * sizeof(lv_color_t), MALLOC_CAP_DMA);
    assert(buf2 != NULL);
#else
    static lv_color_t *buf2 = NULL;
#endif

    static lv_disp_buf_t disp_buf;

    uint32_t size_in_px = DISP_BUF_SIZE;

#if defined CONFIG_LV_TFT_DISPLAY_CONTROLLER_IL3820 || defined CONFIG_LV_TFT_DISPLAY_CONTROLLER_JD79653A || defined CONFIG_LV_TFT_DISPLAY_CONTROLLER_UC8151D || defined CONFIG_LV_TFT_DISPLAY_CONTROLLER_SSD1306

    /* Actual size in pixels, not bytes. */
    size_in_px *= 8;
#endif

    /* Initialize the working buffer depending on the selected display.
     * NOTE: buf2 == NULL when using monochrome displays. */
    lv_disp_buf_init(&disp_buf, buf1, buf2, size_in_px);

    lv_disp_drv_t disp_drv;
    lv_disp_drv_init(&disp_drv);
    disp_drv.flush_cb = disp_driver_flush;

    /* When using a monochrome display we need to register the callbacks:
     * - rounder_cb
     * - set_px_cb */
#ifdef CONFIG_LV_TFT_DISPLAY_MONOCHROME
    disp_drv.rounder_cb = disp_driver_rounder;
    disp_drv.set_px_cb = disp_driver_set_px;
#endif

    disp_drv.buffer = &disp_buf;
    lv_disp_drv_register(&disp_drv);

    /* Register an input device when enabled on the menuconfig */
#if CONFIG_LV_TOUCH_CONTROLLER != TOUCH_CONTROLLER_NONE
    lv_indev_drv_t indev_drv;
    lv_indev_drv_init(&indev_drv);
    indev_drv.read_cb = touch_driver_read;
    indev_drv.type = LV_INDEV_TYPE_POINTER;
    lv_indev_drv_register(&indev_drv);
#endif

    /* Create and start a periodic timer interrupt to call lv_tick_inc */
    const esp_timer_create_args_t periodic_timer_args = {
        .callback = &lv_tick_task,
        .name = "periodic_gui"};
    esp_timer_handle_t periodic_timer;
    ESP_ERROR_CHECK(esp_timer_create(&periodic_timer_args, &periodic_timer));
    ESP_ERROR_CHECK(esp_timer_start_periodic(periodic_timer, LV_TICK_PERIOD_MS * 1000));

    //Home_Page_Create();

    //lv_split_jpeg_init();
    setup_ui(&guider_ui);
    events_init(&guider_ui);

    /* Create the demo application */
    // create_demo_application();

    while (1)
    {
        /* Delay 1 tick (assumes FreeRTOS tick is 10ms */
        vTaskDelay(pdMS_TO_TICKS(10));

        /* Try to take the semaphore, call lvgl related function on success */
        if (pdTRUE == xSemaphoreTake(xGuiSemaphore, portMAX_DELAY))
        {
            lv_task_handler();
            xSemaphoreGive(xGuiSemaphore);
        }
    }

    /* A task should NEVER return */
    free(buf1);
#ifndef CONFIG_LV_TFT_DISPLAY_MONOCHROME
    free(buf2);
#endif
    vTaskDelete(NULL);
}

static void create_demo_application(void)
{
    /* When using a monochrome display we only show "Hello World" centered on the
     * screen */
#if defined CONFIG_LV_TFT_DISPLAY_MONOCHROME || \
    defined CONFIG_LV_TFT_DISPLAY_CONTROLLER_ST7735S

    /* use a pretty small demo for monochrome displays */
    /* Get the current screen  */
    lv_obj_t *scr = lv_disp_get_scr_act(NULL);

    /*Create a Label on the currently active screen*/
    lv_obj_t *label1 = lv_label_create(scr, NULL);

    /*Modify the Label's text*/
    lv_label_set_text(label1, "Hello\nworld");

    /* Align the Label to the center
     * NULL means align on parent (which is the screen now)
     * 0, 0 at the end means an x, y offset after alignment*/
    lv_obj_align(label1, NULL, LV_ALIGN_CENTER, 0, 0);

#else
    /* Otherwise we show the selected demo */

#if defined CONFIG_LV_USE_DEMO_WIDGETS
    lv_demo_widgets();
#elif defined CONFIG_LV_USE_DEMO_KEYPAD_AND_ENCODER
    lv_demo_keypad_encoder();
#elif defined CONFIG_LV_USE_DEMO_BENCHMARK
    lv_demo_benchmark();
#elif defined CONFIG_LV_USE_DEMO_STRESS
    lv_demo_stress();
#else
#error "No demo application selected."
#endif
#endif
}

static void lv_tick_task(void *arg)
{
    (void)arg;

    lv_tick_inc(LV_TICK_PERIOD_MS);
}
