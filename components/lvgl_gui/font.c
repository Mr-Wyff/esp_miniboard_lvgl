#include "lvgl_gui.h"
#include "lvgl.h"
#include "guider_fonts.h"
#include "lv_font.h"
#include "gui_guider.h"
#include "./lv_examples/src/lv_examples.h"
#include "userfont.h"
#include "image.h"
#include "../lvgl/src/lv_widgets/lv_bar.h"
#include "../lvgl/src/lv_core/lv_style.h"


void font_img(const void *img_src,uint8_t pos_x,uint8_t pos_y)
{

    lv_obj_t *src = lv_scr_act();

    lv_obj_t *img1 = lv_img_create(lv_scr_act(), NULL);
    lv_img_set_src(img1, img_src);
    lv_obj_set_pos(img1,pos_x,pos_y);

    lv_obj_t * temperature_bar = lv_bar_create(lv_scr_act(), NULL);
    lv_obj_set_size(temperature_bar, 60, 10);
    lv_obj_set_pos(temperature_bar,50,170);
    lv_bar_set_anim_time(temperature_bar, 2000);
    lv_bar_set_range(temperature_bar,0,100);
    lv_bar_set_value(temperature_bar, 50, LV_ANIM_ON);
    //温度值

    lv_obj_t *temperature_label;
    static lv_style_t font_style;
    lv_style_init(&font_style);
    lv_style_set_text_color(&font_style, LV_STATE_DEFAULT, LV_COLOR_ORANGE);
    lv_style_set_text_font(&font_style, LV_STATE_DEFAULT, &user_fonts_symbol_10);

    temperature_label = lv_label_create(src, NULL);
    lv_obj_add_style(temperature_label, LV_LABEL_PART_MAIN, &font_style);
    lv_label_set_text(temperature_label, "0123456789 :%℃月号周一二三四五六日北京上海商丘优西南风2级");
    lv_obj_set_pos(temperature_label, 120, 165);

}





