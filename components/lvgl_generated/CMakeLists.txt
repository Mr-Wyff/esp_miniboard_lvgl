if(ESP_PLATFORM)

file(GLOB_RECURSE SOURCES *.c
                          ./images/* .c

)

idf_component_register(SRCS ${SOURCES}
                       INCLUDE_DIRS . ./guider_customer_fonts ./guider_fonts ./images ../lvgl/src/lv_font ../lvgl/src/lv_widgets
                       REQUIRES lvgl)

else()
    message(FATAL_ERROR "LVGL LV examples: ESP_PLATFORM is not defined. Try reinstalling ESP-IDF.")
endif()
