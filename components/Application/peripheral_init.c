#include "peripheral_init.h"
#include "wifi.h"
#include "sntp_time.h"

void peripheral_init(void)
{
    wifi_connect();

    xTaskCreate(&time_date_task, "time_date_task", 2048*5, NULL, 5, NULL);

}
