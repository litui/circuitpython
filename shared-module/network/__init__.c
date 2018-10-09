/*
 * This file is part of the MicroPython project, http://micropython.org/
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2018 Nick Moore
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

#include "py/mphal.h"

#include "shared-bindings/random/__init__.h"

void network_module_create_random_mac_address(uint8_t *mac) {
    uint32_t rb1 = shared_modules_random_getrandbits(24);
    uint32_t rb2 = shared_modules_random_getrandbits(24);
    // first octet has multicast bit (0) cleared and local bit (1) set
    // everything else is just set randomly
    mac[0] = ((uint8_t)(rb1 >> 16) & 0xfe) | 0x02;
    mac[1] = (uint8_t)(rb1 >> 8);
    mac[2] = (uint8_t)(rb1);
    mac[3] = (uint8_t)(rb2 >> 16);
    mac[4] = (uint8_t)(rb2 >> 8);
    mac[5] = (uint8_t)(rb2);
}

