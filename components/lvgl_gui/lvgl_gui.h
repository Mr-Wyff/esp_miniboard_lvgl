#ifndef __LVGL_GUI_H
#define __LVGL_GUI_H


#include "lvgl.h"
#include "guider_fonts.h"
#include "lv_font.h"
#include "gui_guider.h"
#include "./lv_examples/src/lv_examples.h"
#include "userfont.h"
#include "image.h"
#include "../lvgl/src/lv_widgets/lv_bar.h"
#include "../lvgl/src/lv_core/lv_style.h"
#include "string.h"
#include "stdio.h"


typedef struct {
    uint8_t hour;
    uint8_t min;
    uint8_t sec;
}S_DATE_TIME;

void lvgl_gui_sample();
void Home_Page_Create(void);
void numtostring_convert(int16_t num,char *str);
void time_label_disp(int hour, int min,int sec, const char *symbol);
void update_time_date(int hour, int min, int sec, int mon,int monday,int weekday);

#endif
