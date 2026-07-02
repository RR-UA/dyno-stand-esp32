#include "include/button.h"

#include "driver/gpio.h"
#include "esp_timer.h"
#include "include/console.h"

static int64_t last_press_us = 0;

/**
 * ISR on button falling edge, debounced, gives tare_sem.
 */
static void IRAM_ATTR button_isr_handler(void *arg) {
    const int64_t now = esp_timer_get_time();
    if (now - last_press_us < DEBOUNCE_US) return;
    last_press_us = now;

    BaseType_t wakeup = pdFALSE;
    xSemaphoreGiveFromISR(tare_sem, &wakeup);
    if (wakeup) portYIELD_FROM_ISR();
}

/**
 * Initializes button GPIO with interrupt on falling edge, shares tare_sem with console.
 */
void button_init(void) {
    const gpio_config_t cfg = {
        .pin_bit_mask = 1ULL << BUTTON_PIN,
        .mode         = GPIO_MODE_INPUT,
        .pull_up_en   = GPIO_PULLUP_ENABLE,
        .intr_type    = GPIO_INTR_NEGEDGE,
    };
    gpio_config(&cfg);
    gpio_isr_handler_add(BUTTON_PIN, button_isr_handler, NULL);
}