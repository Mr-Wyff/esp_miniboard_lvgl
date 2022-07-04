if(ESP_PLATFORM)

file(GLOB_RECURSE SOURCES *.c
                  ./images/*.c
                  ./userfont/*.c
                  ../lvgl/src/lv_widgets/*.c
                  ../lvgl/src/lv_themes/lv_themes.c
                  ../lvgl/src/lv_font/*.c
)

idf_component_register(SRCS ${SOURCES}
                       INCLUDE_DIRS . ./images ./userfont ../lvgl/src/lv_widgets ../lvgl/src/lv_themes ../lvgl/src/lv_font/
                       REQUIRES lvgl)

else()
    message(FATAL_ERROR "LVGL LV examples: ESP_PLATFORM is not defined. Try reinstalling ESP-IDF.")
endif()
