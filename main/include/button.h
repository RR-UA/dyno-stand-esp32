#pragma once

#define BUTTON_PIN  GPIO_NUM_9
#define DEBOUNCE_US 200000

/**
 * Initializes button GPIO with interrupt on falling edge, shares tare_sem with console.
 */
void button_init(void);