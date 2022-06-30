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
	lv_obj_t *screen_img_1;
}lv_ui;

extern lv_ui guider_ui;

void setup_ui(lv_ui *ui);
void setup_scr_screen(lv_ui *ui);

LV_IMG_DECLARE(_mini_board_alpha_223x223);
LV_IMG_DECLARE(_wx_alpha_170x169);
LV_IMG_DECLARE(cloud);

#ifdef __cplusplus
}
#endif
#endif
