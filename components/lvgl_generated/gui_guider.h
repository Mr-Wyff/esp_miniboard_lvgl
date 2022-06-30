/*
 * Copyright 2022 NXP
 * SPDX-License-Identifier: MIT
 */

#ifndef GUI_GUIDER_H
#define GUI_GUIDER_H
#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"
#include "guider_fonts.h"

typedef struct
{
	lv_obj_t *screen;
	lv_obj_t *screen_canvas_1;
	lv_obj_t *screen_time_label;
	lv_obj_t *screen_whether_img;
	lv_obj_t *screen_temp_img;
	lv_obj_t *screen_city_label;
	lv_obj_t *screen_hum_img;
	lv_obj_t *screen_temp_bar;
	lv_obj_t *screen_date_label;
	lv_obj_t *screen_hum_bar;
	lv_obj_t *screen_logo_img;
}lv_ui;

void setup_ui(lv_ui *ui);
extern lv_ui guider_ui;
void setup_scr_screen(lv_ui *ui);
LV_IMG_DECLARE(_cloud2_alpha_89x88);
LV_IMG_DECLARE(_dabai_alpha_100x100);
LV_IMG_DECLARE(_Pm3XE4eMqr_jpg_alpha_48x55);
LV_IMG_DECLARE(_shidu_jpg_alpha_40x55);

LV_IMG_DECLARE(_mini_board_alpha_223x223);



#ifdef __cplusplus
}
#endif
#endif
