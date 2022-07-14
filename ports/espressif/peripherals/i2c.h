/*
 * This file is part of the MicroPython project, http://micropython.org/
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2020 microDev
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#ifndef MICROPY_INCLUDED_ESPRESSIF_PERIPHERALS_I2C_HANDLER_H
#define MICROPY_INCLUDED_ESPRESSIF_PERIPHERALS_I2C_HANDLER_H

#include "driver/i2c.h"

#ifndef ESPRESSIF_I2C_SET_TIMEOUT_PERCENT_OF_MAX
#define ESPRESSIF_I2C_SET_TIMEOUT_PERCENT_OF_MAX 66
#endif

#if ESPRESSIF_I2C_SET_TIMEOUT_PERCENT_OF_MAX
#include "soc/i2c_reg.h"
// Determine size of memory location used to store timeout.
#if defined(I2C_TIME_OUT_REG_M)  // Standard on ESP32
    #define ESP32_I2C_TIMEOUT_MAX I2C_TIME_OUT_REG_M
#elif defined(I2C_TIME_OUT_VALUE_M)  // ESP32 S3, possibly others.
    #define ESP32_I2C_TIMEOUT_MAX I2C_TIME_OUT_VALUE_M
#else
    #define ESP32_I2C_TIMEOUT_MAX 1048576;  // Assume same values as basic ESP32.
#endif // defined(I2C_TIME_OUT_REG_M)
#endif // ESPRESSIF_I2C_SET_TIMEOUT_PERCENT_OF_MAX

extern void i2c_reset(void);
extern void never_reset_i2c(i2c_port_t num);
extern esp_err_t peripherals_i2c_init(i2c_port_t num, const i2c_config_t *i2c_conf);
extern void peripherals_i2c_deinit(i2c_port_t num);
extern i2c_port_t peripherals_i2c_get_free_num(void);

#endif  // MICROPY_INCLUDED_ESPRESSIF_PERIPHERALS_I2C_HANDLER_H
