#include "../../lvgl.h"

/*******************************************************************************
 * Tool: MCU_Font V2.0
 * Time: 2022-07-02 11:44:14
 * Bpp: 4
 * LineHeight: 17 px
 * BaseLine: 2
 * 
 * FontCount: 1
 * FontSize_1: 10px  FontFamily_1: 幼圆  
 ******************************************************************************/

#ifndef USER_FONTS_SYMBOL_15
#define USER_FONTS_SYMBOL_15 1
#endif

#if USER_FONTS_SYMBOL_15

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t gylph_bitmap[] = {

    /* U+32 "2" */
    0x6, 0xff, 0xf7, 0x79, 0x0, 0x2e, 0xc5, 0x0, 
    0x5, 0xaa, 0x0, 0x5, 0x0, 0x0, 0xb, 0x0, 
    0x0, 0x75, 0x0, 0x7, 0x30, 0x0, 0x82, 0x0, 
    0x9, 0x10, 0x0, 0x81, 0x0, 0x3, 0xff, 0xff, 
    0xff, 

    /* U+37 "7" */
    0x7f, 0xff, 0xff, 0x79, 0x30, 0x0, 0x70, 0x70, 
    0x0, 0x45, 0x0, 0x0, 0x8, 0x0, 0x0, 0x5, 
    0x50, 0x0, 0x0, 0xa1, 0x0, 0x0, 0x5a, 0x0, 
    0x0, 0x7, 0x70, 0x0, 0x0, 0xc7, 0x0, 0x0, 
    0x1e, 0x70, 0x0, 0x1, 0xe7, 0x0, 0x0, 

    /* U+2103 "℃" */
    0x96, 0x90, 0x0, 0x0, 0x0, 0x1, 0x80, 0x81, 
    0x5c, 0xff, 0xf7, 0x65, 0x59, 0x5a, 0xf7, 0x0, 
    0x2c, 0xf5, 0x0, 0x7f, 0x30, 0x0, 0x0, 0xc5, 
    0x3, 0xf7, 0x0, 0x0, 0x0, 0x55, 0x5, 0xf3, 
    0x0, 0x0, 0x0, 0x0, 0x7, 0xe1, 0x0, 0x0, 
    0x0, 0x0, 0x7, 0xe1, 0x0, 0x0, 0x0, 0x0, 
    0x3, 0xf5, 0x0, 0x0, 0x0, 0x0, 0x0, 0xca, 
    0x0, 0x0, 0x0, 0x7, 0x0, 0x5f, 0x90, 0x0, 
    0x5, 0xc3, 0x0, 0x5, 0xff, 0xab, 0xfd, 0x20, 
    0x0, 0x0, 0x3, 0x55, 0x10, 0x0, 
};

/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
/* id = 0 reserved */  {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0},
/* U+32 "2" */  {.bitmap_index = 0, .adv_w = 136, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
/* U+37 "7" */  {.bitmap_index = 33, .adv_w = 136, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
/* U+2103 "℃" */  {.bitmap_index = 72, .adv_w = 280, .box_w = 12, .box_h = 13, .ofs_x = 2, .ofs_y = -1},
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/

static const uint16_t unicode_list_1[] = {

    0x32, 0x37, 0x2103, 
};

/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 0, .range_length = 8451, .glyph_id_start = 1,
        .unicode_list = unicode_list_1, .glyph_id_ofs_list = NULL, .list_length = 3, .type = LV_FONT_FMT_TXT_CMAP_SPARSE_TINY
    }
};

/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/
/*Store all the custom data of the font*/
static lv_font_fmt_txt_dsc_t font_dsc = {
    .glyph_bitmap = gylph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = NULL,
    .kern_scale = 0,
    .cmap_num = 1,
    .bpp = 4,
    .kern_classes = 0,
    .bitmap_format = 0
};

/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
lv_font_t user_fonts_symbol_15 = {
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 17,          /*The maximum line height required by the font*/
    .base_line = 2,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
    .dsc = &font_dsc           /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
};
#endif /*#if USER_FONTS_SYMBOL_15*/
