if(ESP_PLATFORM)

file(GLOB_RECURSE SOURCES *.c
)

idf_component_register(SRCS ${SOURCES}
                       INCLUDE_DIRS .
                       REQUIRES lvgl json nvs_flash spiffs mbedtls esp-tls
                       EMBED_TXTFILES server_root_cert.pem)

else()
    message(FATAL_ERROR "LVGL LV examples: ESP_PLATFORM is not defined. Try reinstalling ESP-IDF.")
endif()
