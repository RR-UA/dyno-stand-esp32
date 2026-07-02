#include <stdio.h>

#include "driver/gpio.h"
#include "include/hx711.h"
#include "include/storage.h"

#define BUTTON_PIN GPIO_NUM_9

/**
 * @function app_main
 * @description Application entry point. Prepares storage and HX711, handling tare persistence lifecycle.
 */
void app_main(void) {
    const gpio_config_t cfg = {
        .pin_bit_mask = 1ULL << BUTTON_PIN,
        .mode         = GPIO_MODE_INPUT,
        .pull_up_en   = GPIO_PULLUP_ENABLE,
    };
    gpio_config(&cfg);

    storage_init();
    hx711_init();

    int32_t saved_offset = 0;

    if (storage_load_tare(&saved_offset)) hx711_set_offset(saved_offset);
    else
        storage_save_tare(hx711_tare());

    while (1) {
        if (gpio_get_level(BUTTON_PIN) == 0) storage_save_tare(hx711_tare());
        printf("%d\n", hx711_read_weight());
    }
}