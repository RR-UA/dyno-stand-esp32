#pragma once

#include <stdint.h>

#define FILTER_SIZE   4
#define BLOCK_SAMPLES 8

#define HX711_DOT_PIN GPIO_NUM_3
#define HX711_SCK_PIN GPIO_NUM_4
#define SCALE_FACTOR  61.4f

/**
 * Initializes GPIO pins for HX711 communication.
 */
void hx711_init(void);

/**
 * Averages N raw ADC readings, stores the result as zero-point offset and returns it.
 * @return Zero-point offset.
 */
int32_t hx711_tare(void);

/**
 * Manually sets the zero-point offset and initializes the filter buffer.
 * @param offset Zero-point offset.
 */
void hx711_set_offset(int32_t offset);

/**
 * Reads current weight in grams, adjusted by tare offset and scale factor.
 * @return Weight in grams.
 */
int hx711_read_weight(void);