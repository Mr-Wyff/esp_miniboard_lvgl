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
#include "lvgl_gui.h"

#include "wifi.h"
#include "https.h"
#include "peripheral_init.h"

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

void setup_scr_screen(lv_ui *ui)
{

    // Write codes screen
    ui->screen = lv_obj_create(NULL, NULL);

    // Write codes screen_time_label
    ui->screen_time_label = lv_label_create(ui->screen, NULL);
    lv_label_set_text(ui->screen_time_label, "11");
    lv_label_set_long_mode(ui->screen_time_label, LV_LABEL_LONG_BREAK);
    lv_label_set_align(ui->screen_time_label, LV_LABEL_ALIGN_CENTER);

    // Write style LV_LABEL_PART_MAIN for screen_time_label
    static lv_style_t style_screen_time_label_main;
    lv_style_reset(&style_screen_time_label_main);

    // Write style state: LV_STATE_DEFAULT for style_screen_time_label_main
    lv_style_set_radius(&style_screen_time_label_main, LV_STATE_DEFAULT, 0);
    lv_style_set_bg_color(&style_screen_time_label_main, LV_STATE_DEFAULT, lv_color_make(0x5a, 0x61, 0x73));
    lv_style_set_bg_grad_color(&style_screen_time_label_main, LV_STATE_DEFAULT, lv_color_make(0x5a, 0x61, 0x73));
    lv_style_set_bg_grad_dir(&style_screen_time_label_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
    lv_style_set_bg_opa(&style_screen_time_label_main, LV_STATE_DEFAULT, 255);
    lv_style_set_text_color(&style_screen_time_label_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_text_font(&style_screen_time_label_main, LV_STATE_DEFAULT, &lv_font_simsun_12);
    lv_style_set_text_letter_space(&style_screen_time_label_main, LV_STATE_DEFAULT, 2);
    lv_style_set_pad_left(&style_screen_time_label_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_right(&style_screen_time_label_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_top(&style_screen_time_label_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_bottom(&style_screen_time_label_main, LV_STATE_DEFAULT, 0);
    lv_obj_add_style(ui->screen_time_label, LV_LABEL_PART_MAIN, &style_screen_time_label_main);
    lv_obj_set_pos(ui->screen_time_label, 51, 71);
    lv_obj_set_size(ui->screen_time_label, 40, 0);

    // Write codes screen_label_1
    ui->screen_label_1 = lv_label_create(ui->screen, NULL);
    lv_label_set_text(ui->screen_label_1, ":");
    lv_label_set_long_mode(ui->screen_label_1, LV_LABEL_LONG_BREAK);
    lv_label_set_align(ui->screen_label_1, LV_LABEL_ALIGN_CENTER);

    // Write style LV_LABEL_PART_MAIN for screen_label_1
    static lv_style_t style_screen_label_1_main;
    lv_style_reset(&style_screen_label_1_main);

    // Write style state: LV_STATE_DEFAULT for style_screen_label_1_main
    lv_style_set_radius(&style_screen_label_1_main, LV_STATE_DEFAULT, 0);
    lv_style_set_bg_color(&style_screen_label_1_main, LV_STATE_DEFAULT, lv_color_make(0x5a, 0x61, 0x73));
    lv_style_set_bg_grad_color(&style_screen_label_1_main, LV_STATE_DEFAULT, lv_color_make(0x5a, 0x61, 0x73));
    lv_style_set_bg_grad_dir(&style_screen_label_1_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
    lv_style_set_bg_opa(&style_screen_label_1_main, LV_STATE_DEFAULT, 255);
    lv_style_set_text_color(&style_screen_label_1_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_text_font(&style_screen_label_1_main, LV_STATE_DEFAULT, &lv_font_simsun_12);
    lv_style_set_text_letter_space(&style_screen_label_1_main, LV_STATE_DEFAULT, 2);
    lv_style_set_pad_left(&style_screen_label_1_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_right(&style_screen_label_1_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_top(&style_screen_label_1_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_bottom(&style_screen_label_1_main, LV_STATE_DEFAULT, 0);
    lv_obj_add_style(ui->screen_label_1, LV_LABEL_PART_MAIN, &style_screen_label_1_main);
    lv_obj_set_pos(ui->screen_label_1, 90, 71);
    lv_obj_set_size(ui->screen_label_1, 5, 0);

    // Write codes screen_label_2
    ui->screen_label_2 = lv_label_create(ui->screen, NULL);
    lv_label_set_text(ui->screen_label_2, "05");
    lv_label_set_long_mode(ui->screen_label_2, LV_LABEL_LONG_BREAK);
    lv_label_set_align(ui->screen_label_2, LV_LABEL_ALIGN_CENTER);

    // Write style LV_LABEL_PART_MAIN for screen_label_2
    static lv_style_t style_screen_label_2_main;
    lv_style_reset(&style_screen_label_2_main);

    // Write style state: LV_STATE_DEFAULT for style_screen_label_2_main
    lv_style_set_radius(&style_screen_label_2_main, LV_STATE_DEFAULT, 0);
    lv_style_set_bg_color(&style_screen_label_2_main, LV_STATE_DEFAULT, lv_color_make(0x5a, 0x61, 0x73));
    lv_style_set_bg_grad_color(&style_screen_label_2_main, LV_STATE_DEFAULT, lv_color_make(0x5a, 0x61, 0x73));
    lv_style_set_bg_grad_dir(&style_screen_label_2_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
    lv_style_set_bg_opa(&style_screen_label_2_main, LV_STATE_DEFAULT, 255);
    lv_style_set_text_color(&style_screen_label_2_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_text_font(&style_screen_label_2_main, LV_STATE_DEFAULT, &lv_font_simsun_12);
    lv_style_set_text_letter_space(&style_screen_label_2_main, LV_STATE_DEFAULT, 2);
    lv_style_set_pad_left(&style_screen_label_2_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_right(&style_screen_label_2_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_top(&style_screen_label_2_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_bottom(&style_screen_label_2_main, LV_STATE_DEFAULT, 0);
    lv_obj_add_style(ui->screen_label_2, LV_LABEL_PART_MAIN, &style_screen_label_2_main);
    lv_obj_set_pos(ui->screen_label_2, 103, 71);
    lv_obj_set_size(ui->screen_label_2, 40, 0);

    // Write codes screen_label_3
    ui->screen_label_3 = lv_label_create(ui->screen, NULL);
    lv_label_set_text(ui->screen_label_3, ":");
    lv_label_set_long_mode(ui->screen_label_3, LV_LABEL_LONG_BREAK);
    lv_label_set_align(ui->screen_label_3, LV_LABEL_ALIGN_CENTER);

    // Write style LV_LABEL_PART_MAIN for screen_label_3
    static lv_style_t style_screen_label_3_main;
    lv_style_reset(&style_screen_label_3_main);

    // Write style state: LV_STATE_DEFAULT for style_screen_label_3_main
    lv_style_set_radius(&style_screen_label_3_main, LV_STATE_DEFAULT, 0);
    lv_style_set_bg_color(&style_screen_label_3_main, LV_STATE_DEFAULT, lv_color_make(0x5a, 0x61, 0x73));
    lv_style_set_bg_grad_color(&style_screen_label_3_main, LV_STATE_DEFAULT, lv_color_make(0x5a, 0x61, 0x73));
    lv_style_set_bg_grad_dir(&style_screen_label_3_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
    lv_style_set_bg_opa(&style_screen_label_3_main, LV_STATE_DEFAULT, 255);
    lv_style_set_text_color(&style_screen_label_3_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_text_font(&style_screen_label_3_main, LV_STATE_DEFAULT, &lv_font_simsun_12);
    lv_style_set_text_letter_space(&style_screen_label_3_main, LV_STATE_DEFAULT, 2);
    lv_style_set_pad_left(&style_screen_label_3_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_right(&style_screen_label_3_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_top(&style_screen_label_3_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_bottom(&style_screen_label_3_main, LV_STATE_DEFAULT, 0);
    lv_obj_add_style(ui->screen_label_3, LV_LABEL_PART_MAIN, &style_screen_label_3_main);
    lv_obj_set_pos(ui->screen_label_3, 142, 71);
    lv_obj_set_size(ui->screen_label_3, 5, 0);

    // Write codes screen_label_4
    ui->screen_label_4 = lv_label_create(ui->screen, NULL);
    lv_label_set_text(ui->screen_label_4, "59");
    lv_label_set_long_mode(ui->screen_label_4, LV_LABEL_LONG_BREAK);
    lv_label_set_align(ui->screen_label_4, LV_LABEL_ALIGN_CENTER);

    // Write style LV_LABEL_PART_MAIN for screen_label_4
    static lv_style_t style_screen_label_4_main;
    lv_style_reset(&style_screen_label_4_main);

    // Write style state: LV_STATE_DEFAULT for style_screen_label_4_main
    lv_style_set_radius(&style_screen_label_4_main, LV_STATE_DEFAULT, 0);
    lv_style_set_bg_color(&style_screen_label_4_main, LV_STATE_DEFAULT, lv_color_make(0x5a, 0x61, 0x73));
    lv_style_set_bg_grad_color(&style_screen_label_4_main, LV_STATE_DEFAULT, lv_color_make(0x5a, 0x61, 0x73));
    lv_style_set_bg_grad_dir(&style_screen_label_4_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
    lv_style_set_bg_opa(&style_screen_label_4_main, LV_STATE_DEFAULT, 255);
    lv_style_set_text_color(&style_screen_label_4_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_text_font(&style_screen_label_4_main, LV_STATE_DEFAULT, &lv_font_simsun_12);
    lv_style_set_text_letter_space(&style_screen_label_4_main, LV_STATE_DEFAULT, 2);
    lv_style_set_pad_left(&style_screen_label_4_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_right(&style_screen_label_4_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_top(&style_screen_label_4_main, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_bottom(&style_screen_label_4_main, LV_STATE_DEFAULT, 0);
    lv_obj_add_style(ui->screen_label_4, LV_LABEL_PART_MAIN, &style_screen_label_4_main);
    lv_obj_set_pos(ui->screen_label_4, 155, 71);
    lv_obj_set_size(ui->screen_label_4, 40, 0);
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

    // lv_split_jpeg_init();
    // setup_ui(&guider_ui);
    // events_init(&guider_ui);
    // lv_example_canvas_2();

    //外设初始化
    lvgl_gui_sample();
    https_sample();

    peripheral_init();
    /* Create the demo application */
    //   create_demo_application();
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
    //     /* When using a monochrome display we only show "Hello World" centered on the
    //      * screen */

    //     /* use a pretty small demo for monochrome displays */
    //     /* Get the current screen  */
    lv_obj_t *scr = lv_disp_get_scr_act(NULL);

    /*Create a Label on the currently active screen*/
    lv_obj_t *label1 = lv_label_create(scr, NULL);

    /*Modify the Label's text*/
    lv_label_set_text(label1, "Hello\nworld");

    //     /* Align the Label to the center
    //      * NULL means align on parent (which is the screen now)
    //      * 0, 0 at the end means an x, y offset after alignment*/
    lv_obj_align(label1, NULL, LV_ALIGN_CENTER, 0, 0);

    // #else
    //     /* Otherwise we show the selected demo */

    // #if defined CONFIG_LV_USE_DEMO_WIDGETS
    //     lv_demo_widgets();
    // #elif defined CONFIG_LV_USE_DEMO_KEYPAD_AND_ENCODER
    //     lv_demo_keypad_encoder();
    // #elif defined CONFIG_LV_USE_DEMO_BENCHMARK
    //     lv_demo_benchmark();
    // #elif defined CONFIG_LV_USE_DEMO_STRESS
    //     lv_demo_stress();
    // #else
    // #error "No demo application selected."
    // #endif
    // #endif

    //    lv_obj_t *main_label = lv_label_create(lv_scr_act(), NULL);
    //   lv_label_set_text(main_label, "12");
    lv_obj_set_width(label1, 50);  //设置宽度
    lv_obj_set_height(label1, 20); //设置高度
    lv_obj_set_size(label1, 20, 50);
    lv_style_set_text_font(label1, LV_STATE_DEFAULT, &lv_font_montserratMedium_25);
}

static void lv_tick_task(void *arg)
{
    (void)arg;

    lv_tick_inc(LV_TICK_PERIOD_MS);
}
