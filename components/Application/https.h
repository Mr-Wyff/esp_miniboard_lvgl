/* Common functions for protocol examples, to establish Wi-Fi or Ethernet connection.

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
 */

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "esp_err.h"
#include "esp_netif.h"

#define CONFIG_EXAMPLE_CONNECT_WIFI 1

#ifdef CONFIG_EXAMPLE_CONNECT_ETHERNET
#define EXAMPLE_INTERFACE get_example_netif()
#endif

#ifdef CONFIG_EXAMPLE_CONNECT_WIFI
#define EXAMPLE_INTERFACE get_example_netif()
#endif

#if !defined (CONFIG_EXAMPLE_CONNECT_ETHERNET) && !defined (CONFIG_EXAMPLE_CONNECT_WIFI)
// This is useful for some tests which do not need a network connection
#define EXAMPLE_INTERFACE NULL
#endif

/**
 * @brief Configure Wi-Fi or Ethernet, connect, wait for IP
 *
 * This all-in-one helper function is used in protocols examples to
 * reduce the amount of boilerplate in the example.
 *
 * It is not intended to be used in real world applications.
 * See examples under examples/wifi/getting_started/ and examples/ethernet/
 * for more complete Wi-Fi or Ethernet initialization code.
 *
 * Read "Establishing Wi-Fi or Ethernet Connection" section in
 * examples/protocols/README.md for more information about this function.
 *
 * @return ESP_OK on successful connection
 */
esp_err_t example_connect(void);

/**
 * Counterpart to example_connect, de-initializes Wi-Fi or Ethernet
 */
esp_err_t example_disconnect(void);

/**
 * @brief Configure stdin and stdout to use blocking I/O
 *
 * This helper function is used in ASIO examples. It wraps installing the
 * UART driver and configuring VFS layer to use UART driver for console I/O.
 */
esp_err_t example_configure_stdin_stdout(void);

/**
 * @brief Returns esp-netif pointer created by example_connect()
 *
 * @note If multiple interfaces active at once, this API return NULL
 * In that case the get_example_netif_from_desc() should be used
 * to get esp-netif pointer based on interface description
 */
esp_netif_t *get_example_netif(void);

/**
 * @brief Returns esp-netif pointer created by example_connect() described by
 * the supplied desc field
 *
 * @param desc Textual interface of created network interface, for example "sta"
 * indicate default WiFi station, "eth" default Ethernet interface.
 *
 */
esp_netif_t *get_example_netif_from_desc(const char *desc);
void https_sample(void);


typedef struct DATA_WEATHER{
    char * day;
    uint8_t code_day;
    char text_day[20];
    int8_t high;
    int8_t low;
    float rainfall;
    char  wind_direction[10];
    uint16_t wind_direction_degree;
    float wind_speed;
    uint8_t humidity;
}sys_weather_t;


//子对象1结构体--Location
typedef struct
{
    char id[32];
    char name[32];
    char country[32];
    char path[64];
    char timezone[32];
    char timezone_offset[32];
}Location;

//子对象2结构体--Now
typedef struct
{
    char text[32];
    char code[32];
    char temperature[32];
}Now;

//用于保存服务器返回的天气数据
typedef struct
{
    Location location;      //子对象1
    Now now;                //子对象2
    char last_update[64];   //子对象3
}Results;

extern  Results results[3];

#ifdef __cplusplus
}
#endif

