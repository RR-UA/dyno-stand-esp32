#pragma once

#include "freertos/FreeRTOS.h"
#include "freertos/semphr.h"

extern SemaphoreHandle_t tare_sem;

/**
 * @function console_init
 * @description Initializes the USB serial console task for handling software commands.
 */
void console_init(void);