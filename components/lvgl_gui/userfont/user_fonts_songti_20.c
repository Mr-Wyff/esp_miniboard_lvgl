#include "../../lvgl.h"

/*******************************************************************************
 * Tool: MCU_Font V2.0
 * Time: 2022-07-02 08:49:26
 * Bpp: 4
 * LineHeight: 33 px
 * BaseLine: 5
 * 
 * FontCount: 1
 * FontSize_1: 20px  FontFamily_1: 幼圆  
 ******************************************************************************/

#ifndef USER_FONTS_SONGTI_20
#define USER_FONTS_SONGTI_20 1
#endif

#if USER_FONTS_SONGTI_20

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t gylph_bitmap[] = {

    /* U+20 " " */
    0x0, 

    /* U+31 "1" */
    0x0, 0x0, 0x3, 0x90, 0x0, 0x0, 0x0, 0x6f, 
    0xa0, 0x0, 0x1e, 0xff, 0xff, 0xa0, 0x0, 0x0, 
    0x0, 0x7f, 0xa0, 0x0, 0x0, 0x0, 0x5f, 0xa0, 
    0x0, 0x0, 0x0, 0x5f, 0xa0, 0x0, 0x0, 0x0, 
    0x5f, 0xa0, 0x0, 0x0, 0x0, 0x5f, 0xa0, 0x0, 
    0x0, 0x0, 0x5f, 0xa0, 0x0, 0x0, 0x0, 0x5f, 
    0xa0, 0x0, 0x0, 0x0, 0x5f, 0xa0, 0x0, 0x0, 
    0x0, 0x5f, 0xa0, 0x0, 0x0, 0x0, 0x5f, 0xa0, 
    0x0, 0x0, 0x0, 0x5f, 0xa0, 0x0, 0x0, 0x0, 
    0x5f, 0xa0, 0x0, 0x0, 0x0, 0x5f, 0xa0, 0x0, 
    0x0, 0x0, 0x5f, 0xa0, 0x0, 0x0, 0x0, 0x5f, 
    0xa0, 0x0, 0x0, 0x0, 0x5f, 0xa0, 0x0, 0x0, 
    0x0, 0x5f, 0xa0, 0x0, 0x0, 0x2, 0xef, 0xf6, 
    0x0, 0x1e, 0xff, 0xff, 0xff, 0xff, 

    /* U+32 "2" */
    0x0, 0x5, 0xcf, 0xff, 0xd7, 0x0, 0x0, 0x3d, 
    0xa2, 0x0, 0x19, 0xfd, 0x10, 0x1e, 0xa0, 0x0, 
    0x0, 0x7, 0xfc, 0x7, 0xf5, 0x0, 0x0, 0x0, 
    0x1e, 0xf5, 0xcf, 0x70, 0x0, 0x0, 0x0, 0xcf, 
    0x7c, 0xff, 0x30, 0x0, 0x0, 0xa, 0xf7, 0x7f, 
    0xd1, 0x0, 0x0, 0x0, 0xcf, 0x70, 0x0, 0x0, 
    0x0, 0x0, 0x1e, 0xf3, 0x0, 0x0, 0x0, 0x0, 
    0x7, 0xfc, 0x0, 0x0, 0x0, 0x0, 0x1, 0xef, 
    0x30, 0x0, 0x0, 0x0, 0x0, 0xaf, 0x50, 0x0, 
    0x0, 0x0, 0x0, 0x7f, 0x60, 0x0, 0x0, 0x0, 
    0x0, 0x5f, 0x30, 0x0, 0x0, 0x0, 0x0, 0x6f, 
    0x30, 0x0, 0x0, 0x0, 0x0, 0x6f, 0x30, 0x0, 
    0x0, 0x0, 0x0, 0x6f, 0x30, 0x0, 0x0, 0x0, 
    0x0, 0x5f, 0x30, 0x0, 0x0, 0x1, 0xa0, 0x3e, 
    0x30, 0x0, 0x0, 0x0, 0x5a, 0x1e, 0x50, 0x0, 
    0x0, 0x0, 0xa, 0x7c, 0x70, 0x0, 0x0, 0x0, 
    0x8, 0xf5, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf3, 

    /* U+35 "5" */
    0x7, 0xff, 0xff, 0xff, 0xff, 0xff, 0x50, 0x7f, 
    0xff, 0xff, 0xff, 0xff, 0xf3, 0x7, 0x50, 0x0, 
    0x0, 0x0, 0x0, 0x0, 0x75, 0x0, 0x0, 0x0, 
    0x0, 0x0, 0xa, 0x50, 0x0, 0x0, 0x0, 0x0, 
    0x0, 0x93, 0x0, 0x0, 0x0, 0x0, 0x0, 0x9, 
    0x30, 0x0, 0x0, 0x0, 0x0, 0x0, 0xb3, 0x0, 
    0x0, 0x0, 0x0, 0x0, 0xa, 0x11, 0x9e, 0xff, 
    0xf7, 0x0, 0x0, 0xa5, 0xd6, 0x0, 0x7, 0xfd, 
    0x10, 0x1e, 0xe3, 0x0, 0x0, 0x5, 0xfc, 0x1, 
    0xe7, 0x0, 0x0, 0x0, 0xc, 0xf5, 0x0, 0x0, 
    0x0, 0x0, 0x0, 0x7f, 0xa0, 0x0, 0x0, 0x0, 
    0x0, 0x5, 0xfc, 0x0, 0x0, 0x0, 0x0, 0x0, 
    0x5f, 0xc5, 0xfc, 0x0, 0x0, 0x0, 0x5, 0xfc, 
    0xcf, 0xe1, 0x0, 0x0, 0x0, 0x7f, 0xae, 0xfc, 
    0x0, 0x0, 0x0, 0xa, 0xf7, 0xaf, 0x50, 0x0, 
    0x0, 0x1, 0xef, 0x33, 0xf5, 0x0, 0x0, 0x0, 
    0x7f, 0x70, 0x3, 0xe9, 0x10, 0x1, 0x9f, 0x90, 
    0x0, 0x0, 0x7e, 0xff, 0xfc, 0x50, 0x0, 

    /* U+39 "9" */
    0x0, 0x0, 0x7e, 0xff, 0xfa, 0x20, 0x0, 0x3, 
    0xfd, 0x40, 0x0, 0x9f, 0x60, 0x3, 0xfe, 0x10, 
    0x0, 0x0, 0x7f, 0x50, 0xaf, 0x50, 0x0, 0x0, 
    0x1, 0xec, 0x3f, 0xe1, 0x0, 0x0, 0x0, 0x7, 
    0xf5, 0xfc, 0x0, 0x0, 0x0, 0x0, 0x5f, 0x7f, 
    0xa0, 0x0, 0x0, 0x0, 0x3, 0xf7, 0xfa, 0x0, 
    0x0, 0x0, 0x0, 0x3f, 0x7f, 0xc0, 0x0, 0x0, 
    0x0, 0x3, 0xf5, 0xfe, 0x10, 0x0, 0x0, 0x0, 
    0x7f, 0x1e, 0xf5, 0x0, 0x0, 0x0, 0x3f, 0xf0, 
    0x7f, 0xc0, 0x0, 0x0, 0x1c, 0x7f, 0x0, 0xcf, 
    0xd2, 0x0, 0x5f, 0x65, 0xf0, 0x0, 0x5c, 0xff, 
    0xfc, 0x20, 0x7f, 0x0, 0x0, 0x0, 0x0, 0x0, 
    0xa, 0xf0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xcf, 
    0x0, 0x0, 0x0, 0x0, 0x0, 0x1e, 0xe0, 0x0, 
    0x0, 0x0, 0x0, 0x5, 0xf7, 0x1, 0xdf, 0x30, 
    0x0, 0x0, 0xce, 0x10, 0x3f, 0xf7, 0x0, 0x0, 
    0xaf, 0x50, 0x1, 0xdf, 0xa0, 0x2, 0xcf, 0x50, 
    0x0, 0x0, 0x7f, 0xff, 0xe7, 0x0, 0x0, 

    /* U+3a ":" */
    0x1d, 0xf7, 0x7f, 0xfe, 0x7f, 0xfe, 0x1d, 0xf7, 
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1d, 0xf7, 
    0x7f, 0xfe, 0x7f, 0xfe, 0x1d, 0xf7, 

    /* U+61 "a" */
    0x0, 0x3, 0xaf, 0xff, 0xfd, 0x70, 0x0, 0x0, 
    0xc, 0xf7, 0x10, 0x0, 0x5f, 0xc0, 0x0, 0xa, 
    0xfa, 0x0, 0x0, 0x0, 0x7f, 0x50, 0x0, 0x7f, 
    0xa0, 0x0, 0x0, 0x5, 0xf7, 0x0, 0x0, 0x0, 
    0x0, 0x0, 0x0, 0x5f, 0x70, 0x0, 0x0, 0x0, 
    0x4, 0x9c, 0xef, 0xf7, 0x0, 0x0, 0x7, 0xff, 
    0xc7, 0x31, 0x5f, 0x70, 0x0, 0x2d, 0xf8, 0x0, 
    0x0, 0x5, 0xf7, 0x0, 0xc, 0xf5, 0x0, 0x0, 
    0x0, 0x5f, 0x70, 0x5, 0xfc, 0x0, 0x0, 0x0, 
    0x5, 0xf7, 0x0, 0x7f, 0xa0, 0x0, 0x0, 0x0, 
    0x5f, 0x70, 0x5, 0xfe, 0x10, 0x0, 0x0, 0x8, 
    0xf7, 0x4, 0x9, 0xfc, 0x20, 0x1, 0x7d, 0xaf, 
    0xa0, 0x80, 0x5, 0xcf, 0xff, 0xe7, 0x0, 0x9f, 
    0xf7, 

    /* U+64 "d" */
    0x0, 0x0, 0x0, 0x0, 0x0, 0x17, 0x10, 0x0, 
    0x0, 0x0, 0x1, 0xef, 0xfe, 0x10, 0x0, 0x0, 
    0x0, 0x0, 0x1, 0xee, 0x10, 0x0, 0x0, 0x0, 
    0x0, 0x0, 0xae, 0x10, 0x0, 0x0, 0x0, 0x0, 
    0x0, 0xae, 0x10, 0x0, 0x0, 0x0, 0x0, 0x0, 
    0xae, 0x10, 0x0, 0x0, 0x0, 0x0, 0x0, 0xae, 
    0x10, 0x0, 0x0, 0x0, 0x0, 0x0, 0xae, 0x10, 
    0x0, 0x0, 0x0, 0x0, 0x0, 0xae, 0x10, 0x0, 
    0x5, 0xcf, 0xff, 0x90, 0xae, 0x10, 0x0, 0x9f, 
    0x80, 0x0, 0x6c, 0xde, 0x10, 0xa, 0xf5, 0x0, 
    0x0, 0x1, 0xee, 0x10, 0x3f, 0xc0, 0x0, 0x0, 
    0x0, 0xae, 0x10, 0xaf, 0x70, 0x0, 0x0, 0x0, 
    0xae, 0x10, 0xcf, 0x30, 0x0, 0x0, 0x0, 0xae, 
    0x10, 0xef, 0x30, 0x0, 0x0, 0x0, 0xae, 0x10, 
    0xef, 0x30, 0x0, 0x0, 0x0, 0xae, 0x10, 0xcf, 
    0x30, 0x0, 0x0, 0x0, 0xae, 0x10, 0xaf, 0x50, 
    0x0, 0x0, 0x0, 0xae, 0x10, 0x5f, 0x70, 0x0, 
    0x0, 0x3, 0xfe, 0x10, 0xc, 0xf3, 0x0, 0x0, 
    0x9, 0xff, 0x30, 0x1, 0xdf, 0x50, 0x2, 0xa7, 
    0xaf, 0xfc, 0x0, 0x7, 0xef, 0xfd, 0x50, 0x96, 
    0x0, 

    /* U+65 "e" */
    0x0, 0x2, 0xaf, 0xff, 0xe6, 0x0, 0x0, 0x6, 
    0xf9, 0x0, 0x5, 0xfd, 0x20, 0x5, 0xf5, 0x0, 
    0x0, 0x1, 0xee, 0x11, 0xea, 0x0, 0x0, 0x0, 
    0x7, 0xf7, 0x7f, 0x50, 0x0, 0x0, 0x0, 0x5f, 
    0xaa, 0xf3, 0x0, 0x0, 0x0, 0x3, 0xfc, 0xcf, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xec, 0xf3, 0x0, 
    0x0, 0x0, 0x0, 0x0, 0xaf, 0x50, 0x0, 0x0, 
    0x0, 0x0, 0x7, 0xf7, 0x0, 0x0, 0x0, 0x0, 
    0x0, 0x3f, 0xc0, 0x0, 0x0, 0x0, 0x5, 0x70, 
    0x7f, 0x70, 0x0, 0x0, 0x2, 0xb1, 0x0, 0x7f, 
    0xa3, 0x0, 0x6, 0xd3, 0x0, 0x0, 0x2a, 0xff, 
    0xff, 0x90, 0x0, 

    /* U+69 "i" */
    0x0, 0x0, 0x7f, 0xd1, 0x0, 0x0, 0x1, 0xef, 
    0xf5, 0x0, 0x0, 0x0, 0x7f, 0xc0, 0x0, 0x0, 
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
    0x0, 0x0, 0x0, 0x0, 0x0, 0x3a, 0x70, 0x0, 
    0x5f, 0xff, 0xff, 0x70, 0x0, 0x0, 0x0, 0x7f, 
    0x70, 0x0, 0x0, 0x0, 0x5f, 0x70, 0x0, 0x0, 
    0x0, 0x5f, 0x70, 0x0, 0x0, 0x0, 0x5f, 0x70, 
    0x0, 0x0, 0x0, 0x5f, 0x70, 0x0, 0x0, 0x0, 
    0x5f, 0x70, 0x0, 0x0, 0x0, 0x5f, 0x70, 0x0, 
    0x0, 0x0, 0x5f, 0x70, 0x0, 0x0, 0x0, 0x5f, 
    0x70, 0x0, 0x0, 0x0, 0x5f, 0x70, 0x0, 0x0, 
    0x0, 0x5f, 0x70, 0x0, 0x0, 0x0, 0x7f, 0x90, 
    0x0, 0x5f, 0xff, 0xff, 0xff, 0xff, 

    /* U+6f "o" */
    0x0, 0x5, 0xcf, 0xff, 0xc5, 0x0, 0x0, 0xa, 
    0xf7, 0x0, 0x6, 0xfc, 0x0, 0xa, 0xf3, 0x0, 
    0x0, 0x3, 0xfc, 0x5, 0xf7, 0x0, 0x0, 0x0, 
    0x5, 0xf7, 0xce, 0x10, 0x0, 0x0, 0x0, 0x1e, 
    0xef, 0xc0, 0x0, 0x0, 0x0, 0x0, 0xcf, 0xfa, 
    0x0, 0x0, 0x0, 0x0, 0xa, 0xff, 0xa0, 0x0, 
    0x0, 0x0, 0x0, 0xaf, 0xfc, 0x0, 0x0, 0x0, 
    0x0, 0xa, 0xfe, 0xe1, 0x0, 0x0, 0x0, 0x1, 
    0xee, 0x7f, 0x50, 0x0, 0x0, 0x0, 0x5f, 0x70, 
    0xce, 0x20, 0x0, 0x0, 0x1e, 0xc0, 0x0, 0xcf, 
    0x60, 0x0, 0x5d, 0xc0, 0x0, 0x0, 0x5c, 0xff, 
    0xfc, 0x50, 0x0, 

    /* U+75 "u" */
    0x0, 0x59, 0x0, 0x0, 0x0, 0x2, 0x90, 0xe, 
    0xff, 0xa0, 0x0, 0x0, 0xcf, 0xfc, 0x0, 0x5, 
    0xfa, 0x0, 0x0, 0x0, 0x3e, 0xc0, 0x0, 0x3f, 
    0xa0, 0x0, 0x0, 0x1, 0xec, 0x0, 0x3, 0xfa, 
    0x0, 0x0, 0x0, 0x1e, 0xc0, 0x0, 0x3f, 0xa0, 
    0x0, 0x0, 0x1, 0xec, 0x0, 0x3, 0xfa, 0x0, 
    0x0, 0x0, 0x1e, 0xc0, 0x0, 0x3f, 0xa0, 0x0, 
    0x0, 0x1, 0xec, 0x0, 0x3, 0xfa, 0x0, 0x0, 
    0x0, 0x1e, 0xc0, 0x0, 0x3f, 0xa0, 0x0, 0x0, 
    0x1, 0xec, 0x0, 0x3, 0xfa, 0x0, 0x0, 0x0, 
    0x1e, 0xc0, 0x0, 0x3f, 0xa0, 0x0, 0x0, 0x3, 
    0xfc, 0x0, 0x1, 0xee, 0x10, 0x0, 0x0, 0xaf, 
    0xe2, 0x0, 0x7, 0xfb, 0x10, 0x3, 0xc5, 0xef, 
    0xfa, 0x0, 0x6, 0xef, 0xff, 0x91, 0x1b, 0x50, 
    0x0, 

    /* U+76 "v" */
    0xcf, 0xff, 0xfc, 0x0, 0x5, 0xff, 0xff, 0x70, 
    0x2e, 0xf5, 0x0, 0x0, 0x1, 0xde, 0x20, 0x0, 
    0x7f, 0x50, 0x0, 0x0, 0xc, 0x50, 0x0, 0x3, 
    0xfc, 0x0, 0x0, 0x5, 0xc0, 0x0, 0x0, 0xa, 
    0xf3, 0x0, 0x0, 0xa7, 0x0, 0x0, 0x0, 0x5f, 
    0xa0, 0x0, 0x1d, 0x30, 0x0, 0x0, 0x1, 0xee, 
    0x10, 0x5, 0xa0, 0x0, 0x0, 0x0, 0x7, 0xf5, 
    0x0, 0xa5, 0x0, 0x0, 0x0, 0x0, 0x3f, 0xc0, 
    0x1c, 0x10, 0x0, 0x0, 0x0, 0x0, 0xcf, 0x35, 
    0x70, 0x0, 0x0, 0x0, 0x0, 0x5, 0xfa, 0xb3, 
    0x0, 0x0, 0x0, 0x0, 0x0, 0x1e, 0xfc, 0x0, 
    0x0, 0x0, 0x0, 0x0, 0x0, 0xaf, 0x50, 0x0, 
    0x0, 0x0, 0x0, 0x0, 0x3, 0xd1, 0x0, 0x0, 
    0x0, 

    /* U+4eac "京" */
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
    0x0, 0x0, 0x0, 0x0, 0x1, 0xea, 0x0, 0x0, 
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
    0x0, 0x0, 0x0, 0x0, 0xaf, 0x30, 0x0, 0x0, 
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
    0x0, 0x0, 0x0, 0x3f, 0xa0, 0x0, 0x0, 0x0, 
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
    0x0, 0x0, 0xa, 0xe1, 0x0, 0x0, 0x0, 0x0, 
    0x0, 0x0, 0x0, 0xef, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xf3, 0x8a, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 
    0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 
    0x90, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
    0x0, 0x6a, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 
    0xaa, 0xaa, 0xa9, 0x40, 0x0, 0x0, 0x0, 0x1e, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xfc, 0x0, 0x0, 0x0, 0x7f, 0x60, 
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
    0x0, 0xaf, 0x30, 0x0, 0x0, 0xae, 0x10, 0x0, 
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
    0x7f, 0x30, 0x0, 0x0, 0xae, 0x10, 0x0, 0x0, 
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x7f, 
    0x30, 0x0, 0x0, 0xae, 0x10, 0x0, 0x0, 0x0, 
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x7f, 0x30, 
    0x0, 0x0, 0xae, 0x10, 0x0, 0x0, 0x0, 0x0, 
    0x0, 0x0, 0x0, 0x0, 0x0, 0x7f, 0x30, 0x0, 
    0x0, 0xae, 0x10, 0x0, 0x0, 0x0, 0x0, 0x0, 
    0x0, 0x0, 0x0, 0x0, 0x7f, 0x30, 0x0, 0x0, 
    0x7e, 0x10, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
    0x0, 0x0, 0x0, 0x7f, 0x30, 0x0, 0x0, 0x5f, 
    0xfd, 0xdd, 0xdd, 0xdd, 0xdd, 0xdd, 0xdd, 0xdd, 
    0xdd, 0xdd, 0xfe, 0x10, 0x0, 0x0, 0x7, 0xdd, 
    0xdd, 0xdd, 0xdd, 0xdf, 0xff, 0xdd, 0xdd, 0xdd, 
    0xdd, 0xc2, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
    0x0, 0x0, 0x5, 0xf5, 0x0, 0x0, 0x0, 0x0, 
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3, 0x20, 
    0x0, 0x5, 0xf5, 0x0, 0x0, 0x75, 0x0, 0x0, 
    0x0, 0x0, 0x0, 0x0, 0x0, 0x3f, 0x70, 0x0, 
    0x5, 0xf5, 0x0, 0x0, 0xcf, 0x50, 0x0, 0x0, 
    0x0, 0x0, 0x0, 0x1, 0xee, 0x10, 0x0, 0x5, 
    0xf5, 0x0, 0x0, 0x1e, 0xf3, 0x0, 0x0, 0x0, 
    0x0, 0x0, 0xa, 0xf3, 0x0, 0x0, 0x5, 0xf5, 
    0x0, 0x0, 0x3, 0xfe, 0x10, 0x0, 0x0, 0x0, 
    0x0, 0x7f, 0x50, 0x0, 0x0, 0x5, 0xf5, 0x0, 
    0x0, 0x0, 0x5f, 0xc0, 0x0, 0x0, 0x0, 0x6, 
    0xfa, 0x0, 0x0, 0x0, 0x5, 0xf5, 0x0, 0x0, 
    0x0, 0x7, 0xfa, 0x0, 0x0, 0x0, 0x5f, 0xa0, 
    0x0, 0x0, 0x0, 0x5, 0xf5, 0x0, 0x0, 0x0, 
    0x0, 0xaf, 0x70, 0x0, 0x5, 0xfc, 0x0, 0x1, 
    0x40, 0x0, 0x5, 0xf5, 0x0, 0x0, 0x0, 0x0, 
    0xc, 0xf3, 0x0, 0x5f, 0xc0, 0x0, 0x7, 0xff, 
    0xa3, 0x26, 0xf5, 0x0, 0x0, 0x0, 0x0, 0x3, 
    0xfe, 0x10, 0xcc, 0x0, 0x0, 0x0, 0x5d, 0xff, 
    0xff, 0xe1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x5f, 
    0x30, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3, 0x54, 
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 

    /* U+4f18 "优" */
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
    0x0, 0x0, 0x5b, 0x0, 0x0, 0x0, 0x0, 0x1b, 
    0x30, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
    0x0, 0xa, 0xe1, 0x0, 0x0, 0x0, 0x5, 0xf5, 
    0xc, 0xfa, 0x20, 0x0, 0x0, 0x0, 0x0, 0x0, 
    0x0, 0xcc, 0x0, 0x0, 0x0, 0x0, 0x5f, 0x30, 
    0x2c, 0xff, 0xc2, 0x0, 0x0, 0x0, 0x0, 0x0, 
    0x1e, 0xa0, 0x0, 0x0, 0x0, 0x5, 0xf3, 0x0, 
    0x1, 0x9f, 0xfa, 0x20, 0x0, 0x0, 0x0, 0x3, 
    0xf5, 0x0, 0x0, 0x0, 0x0, 0x5f, 0x30, 0x0, 
    0x0, 0x9, 0xfe, 0x10, 0x0, 0x0, 0x0, 0x7f, 
    0x30, 0x0, 0x0, 0x0, 0x7, 0xf3, 0x0, 0x0, 
    0x0, 0x0, 0x40, 0x0, 0x0, 0x0, 0xa, 0xe1, 
    0x0, 0x0, 0x0, 0x0, 0x7e, 0x10, 0x0, 0x0, 
    0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0xea, 0x7, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0x50, 0x0, 0x5f, 0x50, 0x15, 
    0x55, 0x55, 0x55, 0xaf, 0x65, 0x55, 0x55, 0x55, 
    0x55, 0x55, 0x50, 0x0, 0xa, 0xf3, 0x0, 0x0, 
    0x0, 0x0, 0xa, 0xe1, 0x17, 0x0, 0x0, 0x0, 
    0x0, 0x0, 0x0, 0x3, 0xff, 0x30, 0x0, 0x0, 
    0x0, 0x0, 0xac, 0x5, 0xf3, 0x0, 0x0, 0x0, 
    0x0, 0x0, 0x0, 0x7f, 0xf3, 0x0, 0x0, 0x0, 
    0x0, 0xc, 0xa0, 0x5f, 0x30, 0x0, 0x0, 0x0, 
    0x0, 0x0, 0x1e, 0xdf, 0x30, 0x0, 0x0, 0x0, 
    0x1, 0xe7, 0x5, 0xf3, 0x0, 0x0, 0x0, 0x0, 
    0x0, 0x7, 0xf8, 0xf3, 0x0, 0x0, 0x0, 0x0, 
    0x5f, 0x50, 0x5f, 0x30, 0x0, 0x0, 0x0, 0x0, 
    0x3, 0xfa, 0x5f, 0x30, 0x0, 0x0, 0x0, 0x7, 
    0xf3, 0x5, 0xf3, 0x0, 0x0, 0x0, 0x0, 0x0, 
    0xcf, 0x35, 0xf3, 0x0, 0x0, 0x0, 0x0, 0xac, 
    0x0, 0x5f, 0x30, 0x0, 0x0, 0x0, 0x0, 0xf, 
    0x70, 0x5f, 0x30, 0x0, 0x0, 0x0, 0x1e, 0xa0, 
    0x5, 0xf3, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
    0x5, 0xf3, 0x0, 0x0, 0x0, 0x5, 0xf5, 0x0, 
    0x5f, 0x30, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
    0x5f, 0x30, 0x0, 0x0, 0x0, 0xae, 0x10, 0x5, 
    0xf3, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x5, 
    0xf3, 0x0, 0x0, 0x0, 0x1e, 0xa0, 0x0, 0x5f, 
    0x30, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x5f, 
    0x30, 0x0, 0x0, 0x7, 0xf3, 0x0, 0x5, 0xf3, 
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x5, 0xf3, 
    0x0, 0x0, 0x1, 0xec, 0x0, 0x0, 0x5f, 0x30, 
    0x0, 0x0, 0x0, 0x2, 0x0, 0x0, 0x5f, 0x30, 
    0x0, 0x0, 0x7f, 0x50, 0x0, 0x5, 0xf3, 0x0, 
    0x0, 0x0, 0xa, 0xe1, 0x0, 0x5, 0xf3, 0x0, 
    0x0, 0x1e, 0xc0, 0x0, 0x0, 0x5f, 0x30, 0x0, 
    0x0, 0x0, 0xae, 0x10, 0x0, 0x5f, 0x30, 0x0, 
    0xa, 0xf3, 0x0, 0x0, 0x5, 0xf3, 0x0, 0x0, 
    0x0, 0xa, 0xc0, 0x0, 0x5, 0xf3, 0x0, 0x5, 
    0xfa, 0x0, 0x0, 0x0, 0x5f, 0x30, 0x0, 0x0, 
    0x0, 0xcc, 0x0, 0x0, 0x5f, 0x30, 0x1, 0xee, 
    0x10, 0x0, 0x0, 0x5, 0xf3, 0x0, 0x0, 0x0, 
    0x1e, 0xa0, 0x0, 0x5, 0xf3, 0x0, 0xcf, 0x30, 
    0x0, 0x0, 0x0, 0x5f, 0x60, 0x0, 0x0, 0xa, 
    0xf5, 0x0, 0x0, 0x5f, 0x30, 0xaf, 0x50, 0x0, 
    0x0, 0x0, 0x1, 0xef, 0xff, 0xff, 0xff, 0xfa, 
    0x0, 0x0, 0x5, 0xf3, 0x5f, 0x60, 0x0, 0x0, 
    0x0, 0x0, 0x0, 0x7a, 0xaa, 0xaa, 0xa5, 0x0, 
    0x0, 0x0, 0x0, 0x0, 0x40, 0x0, 0x0, 0x0, 
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 

    /* U+5317 "北" */
    0x0, 0x0, 0x0, 0x0, 0x0, 0x17, 0x0, 0x0, 
    0x0, 0x46, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
    0x0, 0x0, 0x0, 0x0, 0x5f, 0x30, 0x0, 0x0, 
    0xac, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
    0x0, 0x0, 0x0, 0x5f, 0x30, 0x0, 0x0, 0xac, 
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
    0x0, 0x0, 0x5f, 0x30, 0x0, 0x0, 0xac, 0x0, 
    0x0, 0x0, 0x0, 0x10, 0x0, 0x0, 0x0, 0x0, 
    0x0, 0x5f, 0x30, 0x0, 0x0, 0xac, 0x0, 0x0, 
    0x0, 0xc, 0xe1, 0x0, 0x0, 0x0, 0x0, 0x0, 
    0x5f, 0x30, 0x0, 0x0, 0xac, 0x0, 0x0, 0x0, 
    0xaf, 0x50, 0x0, 0x0, 0x0, 0x0, 0x0, 0x5f, 
    0x30, 0x0, 0x0, 0xac, 0x0, 0x0, 0xa, 0xf7, 
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x5f, 0x30, 
    0x0, 0x0, 0xac, 0x0, 0x0, 0x9f, 0x90, 0x0, 
    0x7, 0xdd, 0xdd, 0xdd, 0xdd, 0xff, 0x30, 0x0, 
    0x0, 0xac, 0x0, 0xc, 0xf7, 0x0, 0x0, 0x7, 
    0xdd, 0xdd, 0xdd, 0xdd, 0xff, 0x30, 0x0, 0x0, 
    0xac, 0x2, 0xdf, 0x70, 0x0, 0x0, 0x0, 0x0, 
    0x0, 0x0, 0x0, 0x5f, 0x30, 0x0, 0x0, 0xac, 
    0x7f, 0xf3, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
    0x0, 0x0, 0x5f, 0x30, 0x0, 0x0, 0xaf, 0xfc, 
    0x20, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
    0x0, 0x5f, 0x30, 0x0, 0x0, 0xaf, 0x70, 0x0, 
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
    0x5f, 0x30, 0x0, 0x0, 0xac, 0x0, 0x0, 0x0, 
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x5f, 
    0x30, 0x0, 0x0, 0xac, 0x0, 0x0, 0x0, 0x0, 
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x5f, 0x30, 
    0x0, 0x0, 0xac, 0x0, 0x0, 0x0, 0x0, 0x0, 
    0x0, 0x0, 0x0, 0x0, 0x0, 0x5f, 0x30, 0x0, 
    0x0, 0xac, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
    0x0, 0x0, 0x0, 0x0, 0x5f, 0x30, 0x0, 0x0, 
    0xac, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
    0x0, 0x0, 0x0, 0x5f, 0x30, 0x0, 0x0, 0xac, 
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
    0x0, 0x0, 0x7f, 0x30, 0x0, 0x0, 0xac, 0x0, 
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
    0x7, 0xff, 0x30, 0x0, 0x0, 0xac, 0x0, 0x0, 
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x9f, 
    0xff, 0x30, 0x0, 0x0, 0xac, 0x0, 0x0, 0x0, 
    0x0, 0x3c, 0x0, 0x0, 0x0, 0x2d, 0xf7, 0x5f, 
    0x30, 0x0, 0x0, 0xac, 0x0, 0x0, 0x0, 0x0, 
    0x5f, 0x0, 0x0, 0x6, 0xff, 0x60, 0x5f, 0x30, 
    0x0, 0x0, 0xac, 0x0, 0x0, 0x0, 0x0, 0x5f, 
    0x0, 0x2, 0xcf, 0xd2, 0x0, 0x5f, 0x30, 0x0, 
    0x0, 0xac, 0x0, 0x0, 0x0, 0x0, 0x7e, 0x0, 
    0x7f, 0xf7, 0x0, 0x0, 0x5f, 0x30, 0x0, 0x0, 
    0xac, 0x0, 0x0, 0x0, 0x0, 0xae, 0x1e, 0xfa, 
    0x20, 0x0, 0x0, 0x5f, 0x30, 0x0, 0x0, 0xac, 
    0x0, 0x0, 0x0, 0x0, 0xcc, 0x7, 0x20, 0x0, 
    0x0, 0x0, 0x5f, 0x30, 0x0, 0x0, 0xae, 0x10, 
    0x0, 0x0, 0x3, 0xf7, 0x0, 0x0, 0x0, 0x0, 
    0x0, 0x5f, 0x30, 0x0, 0x0, 0x5f, 0xc3, 0x22, 
    0x22, 0x3d, 0xe1, 0x0, 0x0, 0x0, 0x0, 0x0, 
    0x5f, 0x30, 0x0, 0x0, 0x9, 0xff, 0xff, 0xff, 
    0xff, 0x50, 0x0, 0x0, 0x0, 0x0, 0x0, 0x4, 
    0x0, 0x0, 0x0, 0x0, 0x5, 0x55, 0x55, 0x50, 
    0x0, 

    /* U+5357 "南" */
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xc, 0xa0, 
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xca, 0x0, 
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
    0x0, 0x0, 0x0, 0x0, 0x0, 0x1e, 0x70, 0x0, 
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x2a, 0xaa, 
    0xaa, 0xaa, 0xaa, 0xaa, 0xab, 0xfd, 0xaa, 0xaa, 
    0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0x24, 0xdd, 0xdd, 
    0xdd, 0xdd, 0xdd, 0xdd, 0xff, 0xed, 0xdd, 0xdd, 
    0xdd, 0xdd, 0xdd, 0xdd, 0xd4, 0x0, 0x0, 0x0, 
    0x0, 0x0, 0x0, 0x5, 0xf3, 0x0, 0x0, 0x0, 
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
    0x0, 0x0, 0x0, 0x7e, 0x10, 0x0, 0x0, 0x0, 
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
    0x0, 0x0, 0xa, 0xc0, 0x0, 0x0, 0x0, 0x0, 
    0x0, 0x0, 0x0, 0x0, 0x0, 0x3f, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0x70, 0x0, 0x0, 0x1e, 0xfa, 0xaa, 0xaa, 
    0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 
    0xef, 0x30, 0x0, 0x5, 0xf5, 0x0, 0x1, 0x81, 
    0x0, 0x0, 0x0, 0x0, 0x7, 0x20, 0x0, 0x3, 
    0xf5, 0x0, 0x0, 0x5f, 0x30, 0x0, 0x3f, 0xc0, 
    0x0, 0x0, 0x0, 0x7, 0xf5, 0x0, 0x0, 0x3f, 
    0x50, 0x0, 0x5, 0xf3, 0x0, 0x0, 0x7f, 0x70, 
    0x0, 0x0, 0x0, 0xcc, 0x0, 0x0, 0x3, 0xf5, 
    0x0, 0x0, 0x5f, 0x30, 0x0, 0x0, 0xce, 0x10, 
    0x0, 0x0, 0x5f, 0x70, 0x0, 0x0, 0x3f, 0x50, 
    0x0, 0x5, 0xf3, 0x0, 0x0, 0x3, 0xc1, 0x0, 
    0x0, 0xc, 0xe1, 0x0, 0x0, 0x3, 0xf5, 0x0, 
    0x0, 0x5f, 0x35, 0xdd, 0xdd, 0xdd, 0xdd, 0xdd, 
    0xde, 0xff, 0xdd, 0xdd, 0xb1, 0x3f, 0x50, 0x0, 
    0x5, 0xf3, 0x4d, 0xdd, 0xdd, 0xdd, 0xdf, 0xfe, 
    0xdd, 0xdd, 0xdd, 0xda, 0x3, 0xf5, 0x0, 0x0, 
    0x5f, 0x30, 0x0, 0x0, 0x0, 0x0, 0x7e, 0x10, 
    0x0, 0x0, 0x0, 0x0, 0x3f, 0x50, 0x0, 0x5, 
    0xf3, 0x0, 0x0, 0x0, 0x0, 0x7, 0xe1, 0x0, 
    0x0, 0x0, 0x0, 0x3, 0xf5, 0x0, 0x0, 0x5f, 
    0x30, 0x0, 0x0, 0x0, 0x0, 0x7e, 0x10, 0x0, 
    0x0, 0x0, 0x0, 0x3f, 0x50, 0x0, 0x5, 0xf3, 
    0x0, 0x0, 0x0, 0x0, 0x7, 0xe1, 0x0, 0x0, 
    0x0, 0x0, 0x3, 0xf5, 0x0, 0x0, 0x5f, 0x33, 
    0xaa, 0xaa, 0xaa, 0xaa, 0xdf, 0xba, 0xaa, 0xaa, 
    0xaa, 0xa6, 0x3f, 0x50, 0x0, 0x5, 0xf3, 0x7f, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xa3, 0xf5, 0x0, 0x0, 0x5f, 0x30, 0x0, 
    0x0, 0x0, 0x0, 0x7e, 0x10, 0x0, 0x0, 0x0, 
    0x0, 0x3f, 0x50, 0x0, 0x5, 0xf3, 0x0, 0x0, 
    0x0, 0x0, 0x7, 0xe1, 0x0, 0x0, 0x0, 0x0, 
    0x3, 0xf5, 0x0, 0x0, 0x5f, 0x30, 0x0, 0x0, 
    0x0, 0x0, 0x7e, 0x10, 0x0, 0x0, 0x0, 0x0, 
    0x3f, 0x50, 0x0, 0x5, 0xf3, 0x0, 0x0, 0x0, 
    0x0, 0x7, 0xe1, 0x0, 0x0, 0x0, 0x0, 0x3, 
    0xf5, 0x0, 0x0, 0x5f, 0x30, 0x0, 0x0, 0x0, 
    0x0, 0x7e, 0x10, 0x0, 0x0, 0x0, 0x0, 0x3f, 
    0x50, 0x0, 0x5, 0xf3, 0x0, 0x0, 0x0, 0x0, 
    0x7, 0xe1, 0x0, 0x1e, 0xff, 0xca, 0xaf, 0xf5, 
    0x0, 0x0, 0x5f, 0x30, 0x0, 0x0, 0x0, 0x0, 
    0x7e, 0x10, 0x0, 0x39, 0xdf, 0xff, 0xf7, 0x0, 
    0x0, 0x1, 0x70, 0x0, 0x0, 0x0, 0x0, 0x0, 
    0x40, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 

    /* U+7ea7 "级" */
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
    0x0, 0x0, 0x3e, 0x30, 0x1, 0x22, 0x22, 0x22, 
    0x22, 0x22, 0x22, 0x22, 0x10, 0x0, 0x0, 0x0, 
    0x0, 0xa, 0xe1, 0x3, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xd1, 0x0, 0x0, 0x0, 
    0x3, 0xfa, 0x0, 0x1, 0x22, 0x23, 0xe8, 0x22, 
    0x22, 0x22, 0x23, 0xcf, 0x70, 0x0, 0x0, 0x0, 
    0xaf, 0x30, 0x0, 0x0, 0x0, 0x1e, 0x70, 0x0, 
    0x0, 0x0, 0x5, 0xf5, 0x0, 0x0, 0x0, 0x3f, 
    0xa0, 0x0, 0x0, 0x0, 0x1, 0xe7, 0x0, 0x0, 
    0x0, 0x0, 0xaf, 0x30, 0x0, 0x0, 0xa, 0xf3, 
    0x0, 0x4, 0xb0, 0x0, 0x1e, 0x70, 0x0, 0x0, 
    0x0, 0xc, 0xc0, 0x0, 0x0, 0x3, 0xfa, 0x0, 
    0x0, 0xcc, 0x0, 0x1, 0xe7, 0x0, 0x0, 0x0, 
    0x3, 0xf7, 0x0, 0x0, 0x0, 0xce, 0x10, 0x0, 
    0x5f, 0x50, 0x0, 0x1e, 0xa0, 0x0, 0x0, 0x0, 
    0x7f, 0x50, 0x0, 0x0, 0x5f, 0x70, 0x0, 0x1e, 
    0xc0, 0x0, 0x1, 0xec, 0x0, 0x0, 0x0, 0xa, 
    0xe1, 0x0, 0x0, 0x1e, 0xc0, 0x0, 0x7, 0xf5, 
    0x0, 0x0, 0x1e, 0xf3, 0x0, 0x0, 0x1, 0xea, 
    0x0, 0x0, 0x7, 0xff, 0xdd, 0xff, 0xfc, 0x0, 
    0x0, 0x1, 0xef, 0x70, 0x0, 0x0, 0x3f, 0xd6, 
    0x54, 0x0, 0x5d, 0xdd, 0xaa, 0xef, 0x50, 0x0, 
    0x0, 0x3f, 0xfc, 0x0, 0x0, 0x1, 0xdf, 0xff, 
    0xf7, 0x0, 0x0, 0x0, 0x3f, 0xa0, 0x0, 0x0, 
    0x3, 0xee, 0xf3, 0x0, 0x0, 0x0, 0x0, 0x3e, 
    0xc0, 0x0, 0x0, 0xc, 0xe1, 0x0, 0x0, 0x0, 
    0x5f, 0x8f, 0x70, 0x0, 0x0, 0x0, 0x3, 0xfa, 
    0x0, 0x0, 0x7, 0xf5, 0x0, 0x0, 0x0, 0x7, 
    0xe3, 0xec, 0x0, 0x0, 0x0, 0x0, 0x5f, 0x50, 
    0x0, 0x5, 0xfa, 0x0, 0x0, 0x0, 0x0, 0xac, 
    0x7, 0xf3, 0x0, 0x0, 0x0, 0xa, 0xe1, 0x0, 
    0x1, 0xee, 0x10, 0x0, 0x0, 0x0, 0xc, 0xa0, 
    0x3f, 0xa0, 0x0, 0x0, 0x1, 0xea, 0x0, 0x0, 
    0xcf, 0x30, 0x1, 0x45, 0x0, 0x3, 0xf7, 0x0, 
    0xaf, 0x30, 0x0, 0x0, 0x7f, 0x30, 0x0, 0xaf, 
    0xcb, 0xef, 0xff, 0xf3, 0x0, 0x5f, 0x30, 0x3, 
    0xfa, 0x0, 0x0, 0x3f, 0xa0, 0x0, 0x3f, 0xff, 
    0xfd, 0xb7, 0x30, 0x0, 0xa, 0xc0, 0x0, 0xa, 
    0xf3, 0x0, 0xa, 0xf3, 0x0, 0x0, 0x23, 0x0, 
    0x0, 0x0, 0x0, 0x1, 0xe7, 0x0, 0x0, 0x3f, 
    0xc0, 0x5, 0xfa, 0x0, 0x0, 0x0, 0x0, 0x0, 
    0x0, 0x0, 0x0, 0x7f, 0x30, 0x0, 0x0, 0x7f, 
    0x73, 0xfe, 0x10, 0x0, 0x0, 0x0, 0x0, 0x0, 
    0x0, 0x0, 0x1e, 0xc0, 0x0, 0x0, 0x0, 0xcf, 
    0xef, 0x30, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
    0x37, 0x7, 0xf5, 0x0, 0x0, 0x0, 0x3, 0xff, 
    0x70, 0x0, 0x0, 0x0, 0x0, 0x0, 0x5a, 0xff, 
    0xc4, 0xea, 0x0, 0x0, 0x0, 0x3, 0xdf, 0xff, 
    0x30, 0x0, 0x0, 0x1, 0x7d, 0xff, 0xfa, 0x20, 
    0xaf, 0x30, 0x0, 0x0, 0x8, 0xff, 0x67, 0xff, 
    0x30, 0x0, 0xc, 0xff, 0xf9, 0x30, 0x0, 0x7f, 
    0x70, 0x0, 0x0, 0x5d, 0xfa, 0x20, 0x6, 0xff, 
    0x60, 0x0, 0x55, 0x0, 0x0, 0x0, 0x3f, 0xa0, 
    0x0, 0x5, 0xdf, 0xd5, 0x0, 0x0, 0x3, 0xff, 
    0x90, 0x0, 0x0, 0x0, 0x0, 0x3f, 0xc0, 0x1, 
    0x7f, 0xff, 0x60, 0x0, 0x0, 0x0, 0x2, 0xdf, 
    0xd2, 0x0, 0x0, 0x0, 0x1e, 0xd1, 0xa, 0xff, 
    0xd5, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x8f, 
    0x70, 0x0, 0x0, 0x0, 0x40, 0x0, 0x57, 0x0, 
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 

    /* U+897f "西" */
    0xcf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe1, 0x25, 
    0x55, 0x55, 0x55, 0x5c, 0xd6, 0x55, 0x55, 0x6f, 
    0xc5, 0x55, 0x55, 0x55, 0x55, 0x20, 0x0, 0x0, 
    0x0, 0x0, 0xa, 0xc0, 0x0, 0x0, 0x1e, 0xa0, 
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
    0x0, 0xa, 0xc0, 0x0, 0x0, 0x1e, 0xa0, 0x0, 
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
    0xa, 0xc0, 0x0, 0x0, 0x1e, 0xa0, 0x0, 0x0, 
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xa, 
    0xc0, 0x0, 0x0, 0x1e, 0xa0, 0x0, 0x0, 0x0, 
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xa, 0xc0, 
    0x0, 0x0, 0x1e, 0xa0, 0x0, 0x0, 0x0, 0x0, 
    0x0, 0x9, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfa, 0x0, 
    0x5f, 0xea, 0xaa, 0xaa, 0xae, 0xfa, 0xaa, 0xaa, 
    0xbf, 0xea, 0xaa, 0xaa, 0xaa, 0xdf, 0x50, 0x7f, 
    0x30, 0x0, 0x0, 0xa, 0xc0, 0x0, 0x0, 0x1e, 
    0xa0, 0x0, 0x0, 0x0, 0x3f, 0x70, 0x7f, 0x30, 
    0x0, 0x0, 0xa, 0xc0, 0x0, 0x0, 0x1e, 0xa0, 
    0x0, 0x0, 0x0, 0x3f, 0x70, 0x7f, 0x30, 0x0, 
    0x0, 0xa, 0xc0, 0x0, 0x0, 0x1e, 0xa0, 0x0, 
    0x0, 0x0, 0x3f, 0x70, 0x7f, 0x30, 0x0, 0x0, 
    0xa, 0xc0, 0x0, 0x0, 0x1e, 0xa0, 0x0, 0x0, 
    0x0, 0x3f, 0x70, 0x7f, 0x30, 0x0, 0x0, 0xa, 
    0xc0, 0x0, 0x0, 0x1e, 0xa0, 0x0, 0x0, 0x0, 
    0x3f, 0x70, 0x7f, 0x30, 0x0, 0x0, 0xa, 0xc0, 
    0x0, 0x0, 0x1e, 0xa0, 0x0, 0x0, 0x0, 0x3f, 
    0x70, 0x7f, 0x30, 0x0, 0x0, 0x1e, 0xa0, 0x0, 
    0x0, 0x1e, 0xa0, 0x0, 0x0, 0x0, 0x3f, 0x70, 
    0x7f, 0x30, 0x0, 0x0, 0x5f, 0x50, 0x0, 0x0, 
    0x1e, 0xa0, 0x0, 0x0, 0x0, 0x3f, 0x70, 0x7f, 
    0x30, 0x0, 0x0, 0xce, 0x10, 0x0, 0x0, 0xc, 
    0xe3, 0x22, 0x22, 0x22, 0x5f, 0x70, 0x7f, 0x30, 
    0x0, 0x2d, 0xf5, 0x0, 0x0, 0x0, 0x7, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0x70, 0x7f, 0x31, 0x5c, 
    0xff, 0x60, 0x0, 0x0, 0x0, 0x0, 0x35, 0x55, 
    0x55, 0x55, 0x7f, 0x70, 0x7f, 0x7f, 0xff, 0xa2, 
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
    0x0, 0x3f, 0x70, 0x7f, 0x34, 0x20, 0x0, 0x0, 
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
    0x3f, 0x70, 0x7f, 0x30, 0x0, 0x0, 0x0, 0x0, 
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3f, 
    0x70, 0x7f, 0x30, 0x0, 0x0, 0x0, 0x0, 0x0, 
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3f, 0x70, 
    0x7f, 0x30, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
    0x0, 0x0, 0x0, 0x0, 0x0, 0x3f, 0x70, 0x5f, 
    0x50, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
    0x0, 0x0, 0x0, 0x0, 0x3f, 0x70, 0x3f, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0x50, 0x5, 0xaa, 0xaa, 
    0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 
    0xaa, 0xaa, 0xa5, 0x0, 

    /* U+98ce "风" */
    0x0, 0x5, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xfa, 0x0, 0x0, 0x0, 
    0x0, 0xcf, 0x72, 0x22, 0x22, 0x22, 0x22, 0x22, 
    0x22, 0x22, 0x22, 0x4c, 0xf7, 0x0, 0x0, 0x0, 
    0x3f, 0x70, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
    0x0, 0x0, 0x0, 0x1e, 0xa0, 0x0, 0x0, 0x3, 
    0xf7, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
    0x3, 0xf5, 0x1, 0xea, 0x0, 0x0, 0x0, 0x3f, 
    0x70, 0x4c, 0x30, 0x0, 0x0, 0x0, 0x0, 0x0, 
    0x7f, 0x30, 0x1e, 0xa0, 0x0, 0x0, 0x3, 0xf7, 
    0x3, 0xfe, 0x10, 0x0, 0x0, 0x0, 0x0, 0xc, 
    0xc0, 0x1, 0xea, 0x0, 0x0, 0x0, 0x3f, 0x70, 
    0x5, 0xfc, 0x0, 0x0, 0x0, 0x0, 0x5, 0xf7, 
    0x0, 0x1e, 0xa0, 0x0, 0x0, 0x3, 0xf7, 0x0, 
    0x7, 0xfa, 0x0, 0x0, 0x0, 0x0, 0xae, 0x10, 
    0x1, 0xea, 0x0, 0x0, 0x0, 0x3f, 0x70, 0x0, 
    0xa, 0xf7, 0x0, 0x0, 0x0, 0x3f, 0x70, 0x0, 
    0x1e, 0xa0, 0x0, 0x0, 0x3, 0xf7, 0x0, 0x0, 
    0xc, 0xf3, 0x0, 0x0, 0xa, 0xf3, 0x0, 0x1, 
    0xea, 0x0, 0x0, 0x0, 0x3f, 0x70, 0x0, 0x0, 
    0x1e, 0xe1, 0x0, 0x3, 0xfa, 0x0, 0x0, 0x1e, 
    0xa0, 0x0, 0x0, 0x3, 0xf7, 0x0, 0x0, 0x0, 
    0x3f, 0xc0, 0x0, 0xce, 0x10, 0x0, 0x1, 0xea, 
    0x0, 0x0, 0x0, 0x3f, 0x70, 0x0, 0x0, 0x0, 
    0x7f, 0xa0, 0x5f, 0x70, 0x0, 0x0, 0x1e, 0xa0, 
    0x0, 0x0, 0x3, 0xf7, 0x0, 0x0, 0x0, 0x0, 
    0xaf, 0x9e, 0xc0, 0x0, 0x0, 0x1, 0xea, 0x0, 
    0x0, 0x0, 0x3f, 0x70, 0x0, 0x0, 0x0, 0x1, 
    0xef, 0xf5, 0x0, 0x0, 0x0, 0x1e, 0xa0, 0x0, 
    0x0, 0x3, 0xf7, 0x0, 0x0, 0x0, 0x0, 0x7, 
    0xfe, 0x10, 0x0, 0x0, 0x1, 0xea, 0x0, 0x0, 
    0x0, 0x3f, 0x50, 0x0, 0x0, 0x0, 0x1, 0xef, 
    0xfc, 0x0, 0x0, 0x0, 0x1e, 0xa0, 0x0, 0x0, 
    0x3, 0xf5, 0x0, 0x0, 0x0, 0x0, 0xcf, 0x4a, 
    0xfa, 0x0, 0x0, 0x1, 0xea, 0x0, 0x0, 0x0, 
    0x5f, 0x50, 0x0, 0x0, 0x0, 0xcf, 0x50, 0xc, 
    0xf5, 0x0, 0x0, 0x1e, 0xa0, 0x0, 0x0, 0x7, 
    0xf3, 0x0, 0x0, 0x0, 0xaf, 0x70, 0x0, 0x3f, 
    0xf3, 0x0, 0x1, 0xea, 0x0, 0x0, 0x0, 0xae, 
    0x10, 0x0, 0x0, 0x9f, 0x70, 0x0, 0x0, 0x5f, 
    0xc0, 0x0, 0x1e, 0xa0, 0x0, 0x30, 0xc, 0xc0, 
    0x0, 0x0, 0x9f, 0x90, 0x0, 0x0, 0x0, 0xaf, 
    0xa0, 0x1, 0xec, 0x0, 0x5f, 0x1, 0xea, 0x0, 
    0x0, 0x9f, 0x90, 0x0, 0x0, 0x0, 0x0, 0xcf, 
    0x50, 0xc, 0xc0, 0x5, 0xf0, 0x3f, 0x70, 0x0, 
    0xcf, 0x90, 0x0, 0x0, 0x0, 0x0, 0x3, 0xfe, 
    0x10, 0xae, 0x10, 0x5f, 0x7, 0xf3, 0x0, 0xcf, 
    0x70, 0x0, 0x0, 0x0, 0x0, 0x0, 0x7, 0xfa, 
    0xa, 0xf3, 0x7, 0xf0, 0xce, 0x10, 0xcf, 0x60, 
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xa, 0xc0, 
    0x5f, 0x50, 0x7e, 0x3f, 0x70, 0x6, 0x20, 0x0, 
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 
    0xec, 0x1c, 0xc7, 0xf3, 0x0, 0x0, 0x0, 0x0, 
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x7, 
    0xff, 0xf7, 0xea, 0x0, 0x0, 0x0, 0x0, 0x0, 
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x9, 
    0xfc, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
    0x0, 
};

/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
/* id = 0 reserved */  {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0},
/* U+20 " " */  {.bitmap_index = 0, .adv_w = 264, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = -1},
/* U+31 "1" */  {.bitmap_index = 1, .adv_w = 264, .box_w = 10, .box_h = 22, .ofs_x = 3, .ofs_y = 1},
/* U+32 "2" */  {.bitmap_index = 111, .adv_w = 264, .box_w = 13, .box_h = 22, .ofs_x = 2, .ofs_y = 1},
/* U+35 "5" */  {.bitmap_index = 254, .adv_w = 264, .box_w = 13, .box_h = 22, .ofs_x = 2, .ofs_y = 1},
/* U+39 "9" */  {.bitmap_index = 397, .adv_w = 264, .box_w = 13, .box_h = 22, .ofs_x = 1, .ofs_y = 1},
/* U+3a ":" */  {.bitmap_index = 540, .adv_w = 264, .box_w = 4, .box_h = 15, .ofs_x = 6, .ofs_y = 1},
/* U+61 "a" */  {.bitmap_index = 570, .adv_w = 264, .box_w = 15, .box_h = 14, .ofs_x = 1, .ofs_y = 1},
/* U+64 "d" */  {.bitmap_index = 675, .adv_w = 264, .box_w = 14, .box_h = 23, .ofs_x = 2, .ofs_y = 1},
/* U+65 "e" */  {.bitmap_index = 836, .adv_w = 264, .box_w = 13, .box_h = 14, .ofs_x = 2, .ofs_y = 1},
/* U+69 "i" */  {.bitmap_index = 927, .adv_w = 264, .box_w = 10, .box_h = 22, .ofs_x = 3, .ofs_y = 1},
/* U+6f "o" */  {.bitmap_index = 1037, .adv_w = 264, .box_w = 13, .box_h = 14, .ofs_x = 2, .ofs_y = 1},
/* U+75 "u" */  {.bitmap_index = 1128, .adv_w = 264, .box_w = 15, .box_h = 15, .ofs_x = 1, .ofs_y = 1},
/* U+76 "v" */  {.bitmap_index = 1241, .adv_w = 264, .box_w = 15, .box_h = 14, .ofs_x = 1, .ofs_y = 1},
/* U+4eac "京" */  {.bitmap_index = 1346, .adv_w = 536, .box_w = 30, .box_h = 32, .ofs_x = 2, .ofs_y = -5},
/* U+4f18 "优" */  {.bitmap_index = 1826, .adv_w = 536, .box_w = 31, .box_h = 32, .ofs_x = 1, .ofs_y = -5},
/* U+5317 "北" */  {.bitmap_index = 2322, .adv_w = 536, .box_w = 30, .box_h = 31, .ofs_x = 1, .ofs_y = -5},
/* U+5357 "南" */  {.bitmap_index = 2787, .adv_w = 536, .box_w = 31, .box_h = 32, .ofs_x = 1, .ofs_y = -5},
/* U+7ea7 "级" */  {.bitmap_index = 3283, .adv_w = 536, .box_w = 31, .box_h = 32, .ofs_x = 1, .ofs_y = -5},
/* U+897f "西" */  {.bitmap_index = 3779, .adv_w = 536, .box_w = 30, .box_h = 28, .ofs_x = 2, .ofs_y = -4},
/* U+98ce "风" */  {.bitmap_index = 4199, .adv_w = 536, .box_w = 31, .box_h = 30, .ofs_x = 1, .ofs_y = -5},
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/

static const uint16_t unicode_list_1[] = {

    0x20, 0x31, 0x32, 0x35, 0x39, 0x3a, 0x61, 0x64, 
    0x65, 0x69, 0x6f, 0x75, 0x76, 0x4eac, 0x4f18, 0x5317, 
    0x5357, 0x7ea7, 0x897f, 0x98ce, 
};

/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 0, .range_length = 39118, .glyph_id_start = 1,
        .unicode_list = unicode_list_1, .glyph_id_ofs_list = NULL, .list_length = 20, .type = LV_FONT_FMT_TXT_CMAP_SPARSE_TINY
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
lv_font_t user_fonts_songti_20 = {
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 33,          /*The maximum line height required by the font*/
    .base_line = 5,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
    .dsc = &font_dsc           /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
};
#endif /*#if USER_FONTS_SONGTI_20*/