set(SOURCES main.c)
set(INCLUDES .)


idf_component_register(SRCS ${SOURCES}
                        INCLUDE_DIRS ${INCLUDES}
                        REQUIRES lvgl_esp32_drivers lvgl lv_examples lvgl_generated lv_lib_split_jpg
)
