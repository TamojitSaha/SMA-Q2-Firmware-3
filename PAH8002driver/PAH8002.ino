// #include "pah8002.h"
// #include "pah8002_comm.h"
// #include "pah8002_api_c.h"
// #include "board.h"
// #include "dd_vendor_1.h"
// #include "uart.h"
// #include "main.h"
// #include "accelerometer.h"
// #include <stdint.h>
// #include <string.h>
// #include <stdlib.h>

#include "PAH8002.h"



const uint8_t init_touch_register_INT_array[][2] = {
  {0x7f, 0x01}, //switch to bank1
  {0xe6, 0xC8},
  {0xe7, 0x00},
  {0xF1, 0x00},
  {0x07, 0x01},
  {0xAE, 0x06},
  {0xAF, 0x07},
  {0xBA, 0x7C},
  {0x6C, 0x10},
  {0x6D, 0x10},
  {0x7A, 0x01},
  {0x6F, 0x10},
  {0x7F, 0x00}, //switch to bank0
  {0x08, 0xFF},
  {0x09, 0x03},
  {0x5A, 0x01},
  {0x5C, 0x58}, //Touch Threshold
  {0x5D, 0x02},
  {0x60, 0x00},
  {0x61, 0x02},
  {0x64, 0x01},
  {0x65, 0x01},
  {0x35, 0x80},
  {0x36, 0x02},
  {0x8C, 0x00},
  {0x8E, 0x00},
  {0xDE, 0x00},
  {0xD9, 0x01},
  {0xDD, 0x04},
  {0x3B, 0x01},
  {0x43, 0x00},
  {0x47, 0x01},
  {0x48, 0x00},
  {0x49, 0x00},
  {0x4A, 0x01},
  {0x4D, 0x01},
  {0x16, 0x01},
  {0x13, 0x01},
  {0x14, 0x01},
  {0x15, 0x01},
  {0x50, 0x01},
  {0x51, 0x01},
  {0x59, 0x00},
  {0x57, 0x00},
  {0x6B, 0x00},
  {0x6C, 0x00},
  {0x3E, 0x00},
  {0x0D, 0x78},
  {0x0E, 0x00},
  {0x7F, 0x02}, //switch to bank2
  {0x17, 0x00},
  {0x18, 0x00},
  {0x1B, 0x01},
  {0x1C, 0x01},
  {0x25, 0x02},
  {0x29, 0x00},
  {0x2d, 0x01},
  {0x4F, 0x0C},
  {0x66, 0x01},
  {0x67, 0x01},
  {0x68, 0x01},
  {0x69, 0x01},
  {0x6A, 0x01},
  //{0x6B, 0x01},
  //{0x6C, 0x01},
  {0x6D, 0x01},
  {0x6E, 0x01},
  {0x6F, 0x01},
  {0x70, 0x01},
  {0x74, 0x01},
  {0x76, 0x00},
  {0x7A, 0x01},
  {0x7B, 0xFF},
  {0x8D, 0x01},
  {0x8F, 0x01},
  {0x92, 0x00},
  {0x7F, 0x01}, //switch to bank1
  {0xA2, 0x40},
  {0x7C, 0x01},
  {0x4C, 0x01},
  {0x4F, 0x07},
  {0x3F, 0x04},
  {0x0C, 0x05},
  {0x4D, 0x05},
  {0x52, 0x05},
  {0x86, 0x50},
  {0x92, 0x1C},
  {0x98, 0x1D},
  {0x9A, 0x42},
  {0x81, 0x01},
  {0x3B, 0x00},
  {0xEA, 0xC9},
  {0xA4, 0x50},
  {0xA5, 0x00},
  {0xA6, 0x52},
  {0xA7, 0x00},
  {0xA8, 0x53},
  {0xA9, 0x00},
  {0xAD, 0x00},
  {0xD6, 0xFF},
  {0xD7, 0x1F},
  {0xD8, 0x01},
  {0xD9, 0x00},
  {0xDA, 0x10},
  {0xDB, 0x00},
  {0xDC, 0x16},
  {0xDD, 0x00},
  {0xDE, 0x17},
  {0xDF, 0x00},
  {0xE0, 0xFE},
  {0xE1, 0x1F},
};
#define INIT_TOUCH_INT_ARRAY_SIZE (sizeof(init_touch_register_INT_array)/sizeof(init_touch_register_INT_array[0]))

const uint8_t init_touch_register_array[][2] = {
  {0x7f, 0x01},   //switch to bank1
  {0x4C, 0x00},
  {0xe6, 0xC8},
  {0xe7, 0x00},
  {0xF1, 0x00},
  {0x07, 0x01},
  {0xAE, 0x06},
  {0xAF, 0x07},
  {0xBA, 0x7C},
  {0x6C, 0x10},
  {0x6D, 0x10},
  {0x7A, 0x01},
  {0x6F, 0x10},
  {0x7F, 0x00},   //switch to bank0
  {0x08, 0xFF},
  {0x09, 0x03},
  {0x5A, 0x01},
  {0x5C, 0x58},   //Touch Threshold
  {0x5D, 0x02},
  {0x60, 0x00},
  {0x61, 0x02},
  {0x64, 0x01},
  {0x65, 0x01},
  {0x35, 0x80},
  {0x36, 0x02},
  {0x84, 0x78},
  {0x8C, 0x00},
  {0x8E, 0x00},
  {0xDE, 0x00},
  {0xD9, 0x01},
  {0xDD, 0x04},
  {0x3B, 0x01},
  {0x43, 0x00},
  {0x47, 0x01},
  {0x48, 0x00},
  {0x49, 0x00},
  {0x4A, 0x01},
  {0x4D, 0x01},
  {0x16, 0x01},
  {0x13, 0x01},
  {0x14, 0x01},
  {0x15, 0x01},
  {0x50, 0x01},
  {0x51, 0x01},
  {0x59, 0x00},
  {0x57, 0x00},
  {0x6B, 0x00},
  {0x6C, 0x00},
  {0x3E, 0x00},
  {0x0D, 0x78},
  {0x0E, 0x00},
  {0x7F, 0x02},   //switch to bank2
  {0x17, 0x00},
  {0x18, 0x00},
  {0x1B, 0x01},
  {0x1C, 0x01},
  {0x25, 0x04},
  {0x29, 0x00},
  {0x2d, 0x01},
  {0x4F, 0x0C},
  {0x66, 0x01},
  {0x67, 0x01},
  {0x68, 0x01},
  {0x69, 0x01},
  {0x6A, 0x01},
  //{0x6B, 0x01},
  //{0x6C, 0x01},
  {0x6D, 0x01},
  {0x6E, 0x01},
  {0x6F, 0x01},
  {0x70, 0x01},
  {0x74, 0x01},
  {0x76, 0x01},
  {0x8D, 0x01},
  {0x8F, 0x01},
  {0x92, 0x00},
  {0x7F, 0x01},   //switch to bank1
  {0xA2, 0x40},
  {0x7C, 0x01},
  {0x4F, 0x07},
  {0x3F, 0x04},
  {0x0C, 0x05},
  {0x4D, 0x05},
  {0x52, 0x05},
  {0x86, 0x50},
  {0x92, 0x1C},
  {0x98, 0x1D},
  {0x9A, 0x42},
  {0x81, 0x01},
  {0x3B, 0x00},
  {0xEA, 0xC9},
  {0xA4, 0x50},
  {0xA5, 0x00},
  {0xA6, 0x52},
  {0xA7, 0x00},
  {0xA8, 0x53},
  {0xA9, 0x00},
  {0xAD, 0x00},
  {0xD6, 0xFF},
  {0xD7, 0x1F},
  {0xD8, 0x01},
  {0xD9, 0x00},
  {0xDA, 0x10},
  {0xDB, 0x00},
  {0xDC, 0x16},
  {0xDD, 0x00},
  {0xDE, 0x17},
  {0xDF, 0x00},
  {0xE0, 0xFE},
  {0xE1, 0x1F},
};
#define INIT_TOUCH_REG_ARRAY_SIZE (sizeof(init_touch_register_array)/sizeof(init_touch_register_array[0]))


const uint8_t init_ppg_register_array[][2] = {
  {0x7f, 0x01},   //switch to bank1
  {0xE6, 0xC8},
  {0xE7, 0x00},
  {0x07, 0x01},
  {0xAE, 0x06},
  {0xAF, 0x07},
  {0x4D, 0x00},
  {0xBA, 0x7C},
  {0xBB, 0x7C},
  {0xBC, 0x7C},
  {0xBD, 0x06},
  {0xBE, 0x06},
  {0xBF, 0x06},
  {0xB1, 0x06},
  {0xB2, 0x06},
  {0xB3, 0x06},
  {0x6A, 0x00},
  {0x6B, 0x01},
  {0x6C, 0x10},
  {0x6D, 0x10},
  {0x7A, 0x00},
  {0x6F, 0x10},
  {0x7F, 0x00},   //switch to bank0
  {0x08, 0xFF},
  {0x09, 0x03},
  {0x4F, 0x0C},
  {0xE6, 0x07},
  {0x8C, 0x00},
  {0xAE, 0x01},
  {0xD0, 0x01},
  {0x8E, 0x00},
  {0xD2, 0x01},
  {0xB0, 0x01},
  {0x27, 0x80},
  {0x28, 0x12},
  {0x35, 0xC0},
  {0x36, 0x12},
  {0x37, 0xC0},
  {0x38, 0x12},
  {0x39, 0xC0},
  {0x3A, 0x12},
  {0xDE, 0x00},
  {0xD9, 0x01},
  {0xDD, 0x04},
  {0x3B, 0x01},
  {0x3C, 0x15},
  {0x3D, 0x15},
  {0x47, 0x01},
  {0x48, 0x01},
  {0x49, 0x01},
  {0x4A, 0x01},
  {0x4B, 0x00},
  {0x4C, 0x00},
  {0x4D, 0x00},
  {0x16, 0x00},
  {0x13, 0x01},
  {0x14, 0x01},
  {0x15, 0x01},
  {0x50, 0x00},
  {0x59, 0x00},
  {0x56, 0x00},
  {0x57, 0x00},
  {0x6B, 0x01},
  {0x6C, 0x00},
  {0x8F, 0x01},
  {0xB1, 0x01},
  {0x3E, 0x02},
  {0x3F, 0x04},
  {0x40, 0x04},
  {0x0D, 0x78},
  {0x0E, 0x00},
  {0x0F, 0xF0},
  {0x10, 0x00},
  {0x11, 0xF0},
  {0x12, 0x00},
  {0x6D, 0xF0},
  {0x6E, 0x00},
  {0x6F, 0x00},
  {0x70, 0x02},
  {0x71, 0x10},
  {0x72, 0x00},
  {0x77, 0x00},
  {0x78, 0x0C},
  {0x79, 0x00},
  {0x7A, 0x08},
  {0x7B, 0x00},
  {0x7C, 0x0B},
  {0x7D, 0x00},
  {0x7E, 0x09},
  {0x80, 0x00},
  {0x81, 0x0D},
  {0x82, 0x00},
  {0x83, 0x07},
  {0x85, 0x01},
  {0x90, 0xF0},
  {0x91, 0x00},
  {0x92, 0x20},
  {0x93, 0x12},
  {0x94, 0x10},
  {0x95, 0x00},
  {0x9A, 0x00},
  {0x9B, 0x0C},
  {0x9C, 0x00},
  {0x9D, 0x08},
  {0x9E, 0x00},
  {0x9F, 0x0B},
  {0xA0, 0x00},
  {0xA1, 0x09},
  {0xA2, 0x00},
  {0xA3, 0x0D},
  {0xA4, 0x00},
  {0xA5, 0x07},
  {0xA7, 0x01},
  {0xB2, 0xF0},
  {0xB3, 0x00},
  {0xB4, 0x20},
  {0xB5, 0x12},
  {0xB6, 0x10},
  {0xB7, 0x00},
  {0xBC, 0x00},
  {0xBD, 0x0C},
  {0xBE, 0x00},
  {0xBF, 0x08},
  {0xC0, 0x00},
  {0xC1, 0x0B},
  {0xC2, 0x00},
  {0xC3, 0x09},
  {0xC4, 0x00},
  {0xC5, 0x0D},
  {0xC6, 0x00},
  {0xC7, 0x07},
  {0xC9, 0x01},
  {0x7F, 0x02},   //switch to bank2
  {0x17, 0x00},
  {0x18, 0x00},
  {0x1B, 0x01},
  {0x1C, 0x01},
  {0x25, 0x02},
  {0x29, 0x00},
  {0x2d, 0x01},
  {0x4F, 0x10},
  {0x66, 0x01},
  {0x67, 0x01},
  {0x68, 0x01},
  {0x69, 0x01},
  {0x6A, 0x01},
  //{0x6B, 0x01},
  //{0x6C, 0x01},
  {0x6D, 0x01},
  {0x6E, 0x01},
  {0x70, 0x01},
  {0x7B, 0xFF},
  {0x7F, 0x01},   //switch to bank1
  {0xA2, 0x40},
  {0x7C, 0x01},
  {0x4F, 0x07},
  {0x3F, 0x04},
  {0x0C, 0x05},
  {0x4D, 0x05},
  {0x52, 0x05},
  {0x86, 0x50},
  {0x92, 0x1C},
  {0x98, 0x1D},
  {0x9A, 0x42},
  {0x81, 0x01},
  {0x3B, 0x00},
  {0xEA, 0xC9},
  {0xA4, 0x50},
  {0xA5, 0x00},
  {0xA6, 0x52},
  {0xA7, 0x00},
  {0xA8, 0x53},
  {0xA9, 0x00},
  {0xD6, 0x40},
  {0xD7, 0x06},
  {0xD8, 0x01},
  {0xD9, 0x00},
  {0xDA, 0x11},
  {0xDB, 0x00},
  {0xDC, 0x84},
  {0xDD, 0x02},
  {0xDE, 0x85},
  {0xDF, 0x02},
  {0xE0, 0x3F},
  {0xE1, 0x06},
};
#define INIT_PPG_REG_ARRAY_SIZE (sizeof(init_ppg_register_array)/sizeof(init_ppg_register_array[0]))

const uint8_t init_ppg_long_register_array[][2] = {
  {0x7f, 0x01},   //switch to bank1
  {0xE6, 0xC8},
  {0xE7, 0x00},
  {0x07, 0x01},
  {0xAE, 0x06},
  {0xAF, 0x07},
  {0x4D, 0x00},
  {0xBA, 0x7C},
  {0xBB, 0x7C},
  {0xBC, 0x7C},
  {0xBD, 0x06},
  {0xBE, 0x06},
  {0xBF, 0x06},
  {0xB1, 0x06},
  {0xB2, 0x06},
  {0xB3, 0x06},
  {0x6A, 0x00},
  {0x6B, 0x01},
  {0x6C, 0x10},
  {0x6D, 0x10},
  {0x7A, 0x00},
  {0x6F, 0x10},
  {0x7F, 0x00},   //switch to bank0
  {0x08, 0xFF},
  {0x09, 0x03},
  {0x4F, 0x0C},
  {0xE6, 0x07},
  {0x8C, 0x00},
  {0xAE, 0x01},
  {0xD0, 0x01},
  {0x8E, 0x00},
  {0xD2, 0x01},
  {0xB0, 0x01},
  {0x27, 0x40},
  {0x28, 0x25},
  {0x35, 0x80},
  {0x36, 0x25},
  {0x37, 0x80},
  {0x38, 0x25},
  {0x39, 0x80},
  {0x3A, 0x25},
  {0xDE, 0x00},
  {0xD9, 0x01},
  {0xDD, 0x04},
  {0x3B, 0x01},
  {0x3C, 0x0A},
  {0x3D, 0x0A},
  {0x47, 0x01},
  {0x48, 0x01},
  {0x49, 0x01},
  {0x4A, 0x01},
  {0x4B, 0x00},
  {0x4C, 0x00},
  {0x4D, 0x00},
  {0x16, 0x00},
  {0x13, 0x01},
  {0x14, 0x01},
  {0x15, 0x01},
  {0x50, 0x00},
  {0x59, 0x00},
  {0x56, 0x00},
  {0x57, 0x00},
  {0x6B, 0x01},
  {0x6C, 0x00},
  {0x8F, 0x01},
  {0xB1, 0x01},
  {0x3E, 0x02},
  {0x3F, 0x02},
  {0x40, 0x02},
  {0x0D, 0x78},
  {0x0E, 0x00},
  {0x0F, 0xC0},
  {0x10, 0x12},
  {0x11, 0xC0},
  {0x12, 0x12},
  {0x6D, 0xF0},
  {0x6E, 0x00},
  {0x6F, 0x00},
  {0x70, 0x02},
  {0x71, 0x10},
  {0x72, 0x00},
  {0x77, 0x00},
  {0x78, 0x0C},
  {0x79, 0x00},
  {0x7A, 0x08},
  {0x7B, 0x00},
  {0x7C, 0x0B},
  {0x7D, 0x00},
  {0x7E, 0x09},
  {0x80, 0x00},
  {0x81, 0x0D},
  {0x82, 0x00},
  {0x83, 0x07},
  {0x85, 0x01},
  {0x90, 0xF0},
  {0x91, 0x00},
  {0x92, 0x00},
  {0x93, 0x25},
  {0x94, 0x10},
  {0x95, 0x00},
  {0x9A, 0x00},
  {0x9B, 0x0C},
  {0x9C, 0x00},
  {0x9D, 0x08},
  {0x9E, 0x00},
  {0x9F, 0x0B},
  {0xA0, 0x00},
  {0xA1, 0x09},
  {0xA2, 0x00},
  {0xA3, 0x0D},
  {0xA4, 0x00},
  {0xA5, 0x07},
  {0xA7, 0x01},
  {0xB2, 0xF0},
  {0xB3, 0x00},
  {0xB4, 0x00},
  {0xB5, 0x25},
  {0xB6, 0x10},
  {0xB7, 0x00},
  {0xBC, 0x00},
  {0xBD, 0x0C},
  {0xBE, 0x00},
  {0xBF, 0x08},
  {0xC0, 0x00},
  {0xC1, 0x0B},
  {0xC2, 0x00},
  {0xC3, 0x09},
  {0xC4, 0x00},
  {0xC5, 0x0D},
  {0xC6, 0x00},
  {0xC7, 0x07},
  {0xC9, 0x01},
  {0x7F, 0x02},   //switch to bank2
  {0x17, 0x00},
  {0x18, 0x00},
  {0x1B, 0x01},
  {0x1C, 0x01},
  {0x25, 0x02},
  {0x29, 0x00},
  {0x2d, 0x01},
  {0x4F, 0x10},
  {0x66, 0x01},
  {0x67, 0x01},
  {0x68, 0x01},
  {0x69, 0x01},
  {0x6A, 0x01},
  //{0x6B, 0x01},
  //{0x6C, 0x01},
  {0x6D, 0x01},
  {0x6E, 0x01},
  {0x70, 0x01},
  {0x7B, 0xFF},
  {0x7F, 0x01},   //switch to bank1
  {0xA2, 0x40},
  {0x7C, 0x01},
  {0x4F, 0x07},
  {0x3F, 0x04},
  {0x0C, 0x05},
  {0x4D, 0x05},
  {0x52, 0x05},
  {0x86, 0x50},
  {0x92, 0x1C},
  {0x98, 0x1D},
  {0x9A, 0x42},
  {0x81, 0x01},
  {0x3B, 0x00},
  {0xEA, 0xC9},
  {0xA4, 0x50},
  {0xA5, 0x00},
  {0xA6, 0x52},
  {0xA7, 0x00},
  {0xA8, 0x53},
  {0xA9, 0x00},
  {0xD6, 0x40},
  {0xD7, 0x06},
  {0xD8, 0x01},
  {0xD9, 0x00},
  {0xDA, 0x11},
  {0xDB, 0x00},
  {0xDC, 0xC4},
  {0xDD, 0x02},
  {0xDE, 0xC5},
  {0xDF, 0x02},
  {0xE0, 0x3F},
  {0xE1, 0x06},
};
#define INIT_PPG_LONG_REG_ARRAY_SIZE (sizeof(init_ppg_long_register_array)/sizeof(init_ppg_long_register_array[0]))

const uint8_t init_stress_register_array[][2] = {
  {0x7f, 0x01},   //switch to bank1
  {0xE6, 0xC8},
  {0xE7, 0x00},
  {0x07, 0x01},
  {0xAE, 0x06},
  {0xAF, 0x07},
  {0x4D, 0x00},
  {0xBA, 0x7C},
  {0xBB, 0x7C},
  {0xBC, 0x7C},
  {0xBD, 0x06},
  {0xBE, 0x06},
  {0xBF, 0x06},
  {0xB1, 0x06},
  {0xB2, 0x06},
  {0xB3, 0x06},
  {0x6A, 0x00},
  {0x6B, 0x01},
  {0x6C, 0x10},
  {0x6D, 0x10},
  {0x7A, 0x00},
  {0x6F, 0x08},
  {0x7F, 0x00},   //switch to bank0
  {0x08, 0xFF},
  {0x09, 0x03},
  {0x4F, 0x0C},
  {0xE6, 0x07},
  {0x8C, 0x00},
  {0xAE, 0x01},
  {0xD0, 0x01},
  {0x8E, 0x00},
  {0xD2, 0x01},
  {0xB0, 0x01},
  {0x27, 0x60},
  {0x28, 0x0F},
  {0x35, 0xA0},
  {0x36, 0x0F},
  {0x37, 0xA0},
  {0x38, 0x0F},
  {0x39, 0xA0},
  {0x3A, 0x0F},
  {0xDE, 0x00},
  {0xD9, 0x01},
  {0xDD, 0x04},
  {0x3B, 0x01},
  {0x3C, 0x02},
  {0x3D, 0x02},
  {0x43, 0x00},
  {0x44, 0x00},
  {0x45, 0x00},
  {0x47, 0x01},
  {0x48, 0x01},
  {0x49, 0x01},
  {0x4A, 0x01},
  {0x4B, 0x00},
  {0x4C, 0x00},
  {0x4D, 0x00},
  {0x16, 0x00},
  {0x13, 0x01},
  {0x14, 0x01},
  {0x15, 0x01},
  {0x50, 0x00},
  {0x59, 0x00},
  {0x56, 0x00},
  {0x57, 0x00},
  {0x6B, 0x01},
  {0x6C, 0x00},
  {0x8F, 0x01},
  {0xB1, 0x01},
  {0x3E, 0x00},
  {0x3F, 0x00},
  {0x40, 0x00},
  {0x0D, 0x78},
  {0x0E, 0x00},
  {0x0F, 0xF0},
  {0x10, 0x00},
  {0x11, 0xF0},
  {0x12, 0x00},
  {0x6D, 0xF0},
  {0x6E, 0x00},
  {0x6F, 0x00},
  {0x70, 0x02},
  {0x71, 0x10},
  {0x72, 0x00},
  {0x77, 0x00},
  {0x78, 0x0C},
  {0x79, 0x00},
  {0x7A, 0x08},
  {0x7B, 0x00},
  {0x7C, 0x0B},
  {0x7D, 0x00},
  {0x7E, 0x09},
  {0x80, 0x00},
  {0x81, 0x0D},
  {0x82, 0x00},
  {0x83, 0x07},
  {0x85, 0x01},
  {0x90, 0xF0},
  {0x91, 0x00},
  {0x92, 0x40},
  {0x93, 0x0F},
  {0x94, 0x10},
  {0x95, 0x00},
  {0x9A, 0x00},
  {0x9B, 0x0C},
  {0x9C, 0x00},
  {0x9D, 0x08},
  {0x9E, 0x00},
  {0x9F, 0x0B},
  {0xA0, 0x00},
  {0xA1, 0x09},
  {0xA2, 0x00},
  {0xA3, 0x0D},
  {0xA4, 0x00},
  {0xA5, 0x07},
  {0xA7, 0x01},
  {0xB2, 0xF0},
  {0xB3, 0x00},
  {0xB4, 0x40},
  {0xB5, 0x0F},
  {0xB6, 0x10},
  {0xB7, 0x00},
  {0xBC, 0x00},
  {0xBD, 0x0C},
  {0xBE, 0x00},
  {0xBF, 0x08},
  {0xC0, 0x00},
  {0xC1, 0x0B},
  {0xC2, 0x00},
  {0xC3, 0x09},
  {0xC4, 0x00},
  {0xC5, 0x0D},
  {0xC6, 0x00},
  {0xC7, 0x07},
  {0xC9, 0x01},
  {0x7F, 0x02},   //switch to bank2
  {0x17, 0x00},
  {0x18, 0x00},
  {0x1B, 0x01},
  {0x1C, 0x01},
  {0x25, 0x02},
  {0x29, 0x00},
  {0x2d, 0x01},
  {0x4F, 0x0C},
  {0x66, 0x01},
  {0x67, 0x01},
  {0x68, 0x01},
  {0x69, 0x01},
  {0x6A, 0x01},
  {0x6D, 0x01},
  {0x6E, 0x01},
  {0x70, 0x01},
  {0x7B, 0xFF},
  {0x7F, 0x01},   //switch to bank1
  {0x22, 0x50},
  {0x48, 0x50},
  {0xA2, 0x40},
  {0x7C, 0x01},
  {0x4F, 0x07},
  {0x3F, 0x04},
  {0x0C, 0x05},
  {0x4D, 0x05},
  {0x52, 0x05},
  {0x86, 0x50},
  {0x92, 0x1C},
  {0x98, 0x1D},
  {0x9A, 0x42},
  {0x81, 0x01},
  {0x3B, 0x00},
  {0xEA, 0xC9},
  {0xA4, 0x50},
  {0xA5, 0x00},
  {0xA6, 0x52},
  {0xA7, 0x00},
  {0xA8, 0x53},
  {0xA9, 0x00},
  {0xD6, 0xA0},
  {0xD7, 0x00},
  {0xD8, 0x01},
  {0xD9, 0x00},
  {0xDA, 0x2C},
  {0xDB, 0x00},
  {0xDC, 0x8B},
  {0xDD, 0x00},
  {0xDE, 0x8C},
  {0xDF, 0x00},
  {0xE0, 0x9F},
  {0xE1, 0x00},
};
#define INIT_STRESS_REG_ARRAY_SIZE (sizeof(init_stress_register_array)/sizeof(init_stress_register_array[0]))


const uint8_t suspend_register_array[][2] = {
  {0x7f, 0x01},   //switch to bank1
  {0x09, 0x01},
  {0x23, 0x01},
  {0xB4, 0x01},
  {0xB7, 0x01},
  {0xE6, 0xC8},
  {0xE7, 0x00},
  {0xF1, 0x00},
  {0x07, 0x01},
  {0xAE, 0x06},
  {0xAF, 0x07},
  {0xBA, 0x7C},
  {0x6C, 0x10},
  {0x6D, 0x10},
  {0x7A, 0x00},
  {0x6F, 0x10},
  {0x7F, 0x00},   //switch to bank0
  {0x08, 0xFF},
  {0x09, 0x03},
  {0xD6, 0x01},
  {0x5C, 0x00},
  {0x5D, 0x05},
  {0x60, 0x00},
  {0x61, 0x03},
  {0x64, 0x05},
  {0x65, 0x05},
  {0x35, 0x80},
  {0x36, 0x02},
  {0x8C, 0x00},
  {0x8E, 0x00},
  {0xDE, 0x00},
  {0xD9, 0x01},
  {0xDD, 0x04},
  {0x3B, 0x01},
  {0x47, 0x01},
  {0x48, 0x00},
  {0x49, 0x00},
  {0x4A, 0x00},
  {0x4D, 0x00},
  {0x16, 0x00},
  {0x13, 0x01},
  {0x14, 0x01},
  {0x15, 0x01},
  {0x50, 0x01},
  {0x51, 0x01},
  {0x59, 0x00},
  {0x57, 0x00},
  {0x6B, 0x00},
  {0x6C, 0x00},
  {0x3E, 0x00},
  {0x43, 0x00},
  {0x0D, 0x78},
  {0x0E, 0x00},
  {0x7F, 0x02},   //switch to bank2
  {0x17, 0x00},
  {0x18, 0x00},
  {0x1B, 0x01},
  {0x1C, 0x01},
  {0x1F, 0x00},
  {0x29, 0x00},
  {0x2d, 0x01},
  {0x2B, 0x00},
  {0x2C, 0x00},
  {0x31, 0x00},
  {0x4F, 0x10},
  {0x66, 0x01},
  {0x67, 0x01},
  {0x68, 0x01},
  {0x69, 0x01},
  {0x6A, 0x01},
  {0x6B, 0x01},
  {0x6C, 0x01},
  {0x6D, 0x01},
  {0x6E, 0x01},
  {0x6F, 0x01},
  {0x70, 0x01},
  {0x74, 0x00},
  {0x76, 0x01},
  {0x78, 0x01},
  {0x7A, 0x01},
  {0x7B, 0xFF},
  {0x8D, 0x01},
  {0x8F, 0x01},
  {0x92, 0x00},
  {0x7F, 0x01},   //switch to bank1
  {0xA2, 0x40},
  {0x7C, 0x01},
  {0x4C, 0x01},
  {0x4F, 0x07},
  {0x3F, 0x04},
  {0x0C, 0x05},
  {0x4D, 0x05},
  {0x52, 0x05},
  {0x86, 0x50},
  {0x92, 0x1C},
  {0x98, 0x1D},
  {0x9A, 0x42},
  {0x81, 0x01},
  {0x3B, 0x00},
  {0xEA, 0xC9},
  {0xA4, 0x50},
  {0xA5, 0x00},
  {0xA6, 0x52},
  {0xA7, 0x00},
  {0xA8, 0x53},
  {0xA9, 0x00},
  {0xD6, 0xFF},
  {0xD7, 0x1F},
  {0xD8, 0x01},
  {0xD9, 0x00},
  {0xDA, 0x10},
  {0xDB, 0x00},
  {0xDC, 0x13},
  {0xDD, 0x00},
  {0xDE, 0x14},
  {0xDF, 0x00},
  {0xE0, 0xFE},
  {0xE1, 0x1F},
  {0x7F, 0x01},   //switch to bank1
  {0xd5, 0x01},
};
#define SUSPEND_REG_ARRAY_SIZE (sizeof(suspend_register_array)/sizeof(suspend_register_array[0]))


//++++++++++++++++++++++PAH8002 functions++++++++++++++++++++++++++++++++++++++++++++++++++++
static bool pah8002_sw_reset() {
  uint8_t               data               ;
  //debug_printf(">>>pah8002_sw_reset\r\n");
  pah8002_wakeup();
  if (0 != pah8002_write_reg(0x7f, 0x00)) {
    goto RTN;
  }
  if (0 != pah8002_read_reg(0, &data)) {
    goto  RTN;
  }
  //debug_printf("ID=%d\r\n", data);
  if (data  != 0x02) {
    goto RTN;
  }
  if (0 != pah8002_write_reg(0xe1, 0)) //write 0 to trigger Software Reset
  {
    goto   RTN;    //delay               5ms
  }
  delay(5);
  //debug_printf("<<<pah8002_sw_reset\r\n");
  return true;
RTN: return false;
}

static bool pah8002_start() {
  uint8_t data = 0;
  int samples_per_read =  HEART_RATE_MODE_SAMPLES_PER_READ ;
  //debug_printf(">>>pah8002_start  \r\n");
  pah8002_wakeup();
  if (0 != pah8002_write_reg(0x7f, 0x01))   {
    goto RTN;
  }
  else if (0 != pah8002_write_reg(0xea, (samples_per_read + 1)))   {
    goto  RTN;
  }
  else if (0 != pah8002_write_reg(0xd5, 1)) //TG enable. REQTIMER_ENABLE
  {
    goto  RTN;
  }
  else if (0 != pah8002_read_reg(0xd5, &data)) //TG enable. REQTIMER_ENABLE
  {
    goto RTN;
  }
  pah8002_check();
  //debug_printf("<<<  pah8002_start  %d\r\n", data);
  return true;
RTN:   return false;
}

static bool pah8002_touch_mode_init() {
  int i = 0 ;
  //debug_printf(">>> pah8002_touch_mode_init \r\n");
  pah8002_wakeup();
  for (i = 0; i < INIT_TOUCH_REG_ARRAY_SIZE; i++)            {
    if ( pah8002_write_reg(  init_touch_register_array[i][0], init_touch_register_array[i][1]) != 0 ) {
      goto RTN;
    }
  }
  //debug_printf("<<< pah8002_touch_mode_init \r\n");
  return   true;
RTN: return   false;


}

static bool pah8002_normal_mode_init() {
  int i = 0 ;
  //debug_printf(">>> pah8002_normal_mode_init \r\n");
  pah8002_wakeup();
  for (i = 0; i < INIT_PPG_REG_ARRAY_SIZE; i++)  {
    if ( pah8002_write_reg( init_ppg_register_array[i][0], init_ppg_register_array[i][1]) != 0 )     {
      goto RTN;
    }
  }
  //debug_printf("<<< pah8002_normal_mode_init \r\n");
  return true;
RTN:  return false;
}

static bool pah8002_stress_mode_init() {
  int i = 0 ;
  //debug_printf(">>> pah8002_stress_mode_init \r\n");
  pah8002_wakeup();
  for (i = 0; i < INIT_STRESS_REG_ARRAY_SIZE; i++)               {
    if ( pah8002_write_reg(  init_stress_register_array[i][0], init_stress_register_array[i][1]) != 0 )     {
      goto RTN;
    }
  }
  //debug_printf("<<< pah8002_stress_mode_init \r\n");
  return  true;
RTN:  return  false;
}

static uint8_t pah8002_get_touch_flag_ppg_mode() {
  static uint8_t touch_sts_output = 1 ;
  int32_t *s = (int32_t *)pah8002_ppg_data ;
  int32_t ch0 ;
  int32_t ch1 ;
  int64_t ir_rawdata;
  int i;
  static int touch_cnt = 0, no_touch_cnt = 0 ;

#define TouchDetection_Upper_TH (600)
#define TouchDetection_Lower_TH (512)
#define TouchDetection_Count_TH  (3)    //(3+1)*50ms  = 200ms                
#define NoTouchDetection_Count_TH (3) //(3+1)*50ms = 200ms   

  for (i = 0; i < HEART_RATE_MODE_SAMPLES_PER_READ; i += TOTAL_CHANNELS)   {
    ch0 = *s; ch1 = *(s + 1);
    ir_rawdata = ch0 - ch1 ;
    ir_rawdata = (ir_rawdata * _ir_dac * _ir_expo) >> 20 ;
    if ( ir_rawdata > TouchDetection_Upper_TH) {
      touch_cnt++; no_touch_cnt = 0;
    } else if ( ir_rawdata < TouchDetection_Lower_TH) {
      no_touch_cnt++; touch_cnt = 0 ;
    } else {
      touch_cnt = 0 ; no_touch_cnt = 0;
    }
    s += TOTAL_CHANNELS;
  }
  if (touch_cnt > TouchDetection_Count_TH)   {
    touch_sts_output = 1;
  }   else if ( no_touch_cnt > NoTouchDetection_Count_TH)   {
    touch_sts_output = 0;
  }
  //debug_printf("<<< pah8002_get_touch_flag_ppg_mode %d, %d\n", touch_cnt, no_touch_cnt);
  //debug_printf("<<< pah8002_get_touch_flag_ppg_mode %d\n", touch_sts_output);
  return touch_sts_output;
}

static bool pah8002_enter_normal_mode() {
  //debug_printf(">>> pah8002_enter_normal_mode\r\n");
  if (_mode == NORMAL_MODE) return true;
  //1. software reset
  if ( !pah8002_sw_reset())  goto  RTN;
  //2. load registers for normal mode
  if (  !pah8002_normal_mode_init())    goto  RTN;
  pah8002_write_reg(0x7f,  0x00);               //Bank0
  pah8002_read_reg(0x0D, &_ir_expo); // IR Exposure Time
  pah8002_write_reg(0x7f, 0x01);               //Bank1
  pah8002_read_reg(0xBA, &_ir_dac); //IR Led DAC
  //3.  enable               sensor
  if (  !pah8002_start()) goto RTN;
  _mode = NORMAL_MODE;
  //debug_printf("<<< pah8002_enter_normal_mode ir_dac %x, ir_expo %x\r\n", _ir_dac, _ir_expo);
  return  true;
RTN:  return false ;
}

static bool pah8002_enter_stress_mode() {
  //debug_printf(">>> pah8002_enter_stress_mode\r\n");
  if (_mode == STRESS_MODE) return true;
  //1.               software               reset
  if ( !pah8002_sw_reset())   goto  RTN;
  //2. load registers for normal mode
  if ( !pah8002_stress_mode_init())  goto RTN;
  pah8002_write_reg(0x7f, 0x00);               //Bank0
  pah8002_read_reg(0x0D, &_ir_expo); // IR Exposure Time
  pah8002_write_reg(0x7f, 0x01);               //Bank1
  pah8002_read_reg(0xBA, &_ir_dac); //IR Led DAC
  //3.               enable               sensor
  if ( !pah8002_start()) goto RTN;
  _mode =  STRESS_MODE;
  //debug_printf("<<< pah8002_enter_stress_mode \r\n");
  return  true;
RTN:  return false ;
}

static bool pah8002_enter_touch_mode() {
  //debug_printf(">>> pah8002_enter_touch_mode\r\n");
  if (_mode == TOUCH_MODE) return true;
  //1.               software               reset
  if ( !pah8002_sw_reset() ) goto RTN;
  //2. load registers for touch mode
  if ( !pah8002_touch_mode_init())   goto  RTN;
  //3.               enable               sensor
  if ( !pah8002_start())  goto  RTN;
  _mode = TOUCH_MODE;
  //debug_printf("<<< pah8002_enter_touch_mode\r\n");
  return  true;
RTN:  return false ;
}

static bool pah8002_get_touch_flag( uint8_t *touch_flag) {
  //debug_printf(">>> pah8002_touch_status \r\n");
  pah8002_wakeup();
  if (0 != pah8002_write_reg(0x7f, 0x02))               {
    goto  RTN;
  } else if (0 != pah8002_read_reg(0x45, touch_flag)) //
  {
    goto RTN;
  }
  //debug_printf("<<< pah8002_touch_status %d\r\n", *touch_flag);
  return   true;
RTN:    return  false;
}

static int pah8002_wakeup() {
  int retry = 0 ;
  int success = 0 ;
  uint8_t data = 0 ;
  pah8002_read_reg(0, &data);
  pah8002_read_reg(0, &data);
  do   {
    pah8002_write_reg(0x7f, 0x00);
    pah8002_read_reg(0, &data);
    if (data == 0x02) success++; else success = 0 ;
    if (success >= 2) break;
    retry ++;
  } while (retry < 20);

  if (_chip_id == 0)  {
    pah8002_read_reg(0x02, &data);
    _chip_id = data & 0xF0 ;
    if (_chip_id != 0xD0) {
      //debug_printf("Not support anymore\r\n");
      while (1) {};
    }
  }
  pah8002_write_reg(0x7f, 0x02);
  pah8002_write_reg(0x70,  0x00);
  //debug_printf("pah8002_wakeup retry %d \r\n", retry);
  return retry;
}

static int pah8002_check() {
  int retry = 0 ;
  int success = 0 ;
  uint8_t data = 0 ;
  uint8_t b1_0xd5 = 0 ;
  uint8_t b1_0xe6 = 0 ;
  pah8002_read_reg(0, &data);
  pah8002_read_reg(0, &data);
  do  {
    pah8002_write_reg(0x7f, 0x00);
    pah8002_read_reg(0, &data);
    if (data == 0x02) success++; else success = 0 ;
    if (success >= 2)   break;
    retry ++;
  } while (retry < 20);
  pah8002_write_reg(0x7f,  0x01);

  pah8002_read_reg(0xd5, &b1_0xd5);
  pah8002_read_reg(0xe6, &b1_0xe6);
  //debug_printf("pah8002_check retry %d \r\n", retry);
  if (b1_0xd5  !=   1)
    //debug_printf("pah8002_check error  Bank1 0xD5 0x%x \r\n", b1_0xd5);
    if (b1_0xe6 !=  0xC8)
      //debug_printf("pah8002_check error  Bank1 0xE6 0x%x \r\n", b1_0xe6);
      return              retry;
}

static bool pah8002_enter_suspend_mode() {
  int i = 0 ;
  //debug_printf("pah8002_enter_suspend_mode");
  pah8002_sw_reset();
  for (i = 0; i < SUSPEND_REG_ARRAY_SIZE; i++)               {
    if ( pah8002_write_reg(suspend_register_array[i][0], suspend_register_array[i][1]) != 0 )     {
      return false;
    }
  }
  _mode = SUSPEND_MODE;
  pah8002_check();
  return true;
}

static bool _pah8002_task() {
  uint8_t cks[4] ;
  uint8_t int_req = 0;
  //debug_printf(">>> pah8002_task\n");
  pah8002_wakeup();
  if (0 != pah8002_write_reg(0x7f, 0x02)) {

  } else if (0 != pah8002_read_reg(0x73, &int_req)) {

  } else {
    if ( (int_req & 0x04) != 0)   {   //overflow
      while (1);
    }
    if ( (int_req & 0x02) != 0)
    { //touch
      //debug_printf("touch               interrupt\n");
    } if ( (int_req & 0x08) != 0)   {
      //overflow
      while (1);
    }
    if ( (int_req & 0x01) != 0)   {
      int samples_per_read = HEART_RATE_MODE_SAMPLES_PER_READ ;
      //debug_printf("FIFO               interrupt\n");
      //pah8002_get_touch_flag(&state->pah8002_touch_flag);
      if (0 !=  pah8002_write_reg(0x7f, 0x03)) {

      } else  if (0 !=   pah8002_burst_read_reg(0, pah8002_ppg_data, samples_per_read * 4))    {

      } else if (0 != pah8002_write_reg(0x7f, 0x02))    {

      }  else if (0  !=   pah8002_burst_read_reg(0x80, cks, 4))    {

      } else if (0 != pah8002_write_reg(0x75, 0x01)) //read fifo first, then clear SRAM FIFO interrupt
      {} else if (0 != pah8002_write_reg(0x75, 0x00))    {

      } else {
        uint32_t  *s  = (uint32_t *)pah8002_ppg_data;
        uint32_t cks_cal = *s;
        uint32_t cks_rx = *((uint32_t *)cks) ;
        uint32_t i ;      //checksum    compare
        for (i = 1; i < samples_per_read; i++)  {
          cks_cal  = cks_cal ^   (*(s + i))  ;
        }
        if (cks_cal != cks_rx)   {
          //debug_printf("checksum error\r\n");
        }   else   {
          //debug_printf("checksum  OK %d\r\n", cks_cal);
        }
        _touch_flag =   pah8002_get_touch_flag_ppg_mode();
      }
    } else {
      //debug_printf("not fifo  interrupt%d\r\n",  int_req);
    }
  }
  //debug_printf("<<< pah8002_task\n");
  return    true;
}

static bool pah8002_normal_long_et_mode_init() {
  int i = 0 ;
  //debug_printf(">>>  pah8002_normal_long_et_mode_init \r\n");
  pah8002_wakeup();
  for (i = 0; i < INIT_PPG_LONG_REG_ARRAY_SIZE; i++)               {
    if ( pah8002_write_reg( init_ppg_long_register_array[i][0], init_ppg_long_register_array[i][1]) != 0 )     {
      goto RTN;
    }
  }
  //debug_printf("<<< pah8002_normal_long_et_mode_init \r\n");
  return     true;
RTN:  return   false;
}

static bool pah8002_enter_normal_long_et_mode() {
  //debug_printf(">>>               pah8002_enter_normal_long_et_mode\r\n");
  if (_mode == NORMAL_LONG_ET_MODE) return true;    //1.   software  reset
  if (   !pah8002_sw_reset())
    goto  RTN;
  //2. load registers for normal mode
  if ( !pah8002_normal_long_et_mode_init())
    goto RTN;
  pah8002_write_reg(0x7f, 0x00);     //Bank0
  pah8002_read_reg(0x0D, &_ir_expo); // IR Exposure Time
  pah8002_write_reg(0x7f,  0x01);     //Bank1
  pah8002_read_reg(0xBA, &_ir_dac); //IR Led DAC
  //3.  enable sensor
  if (  !pah8002_start())  goto RTN;
  _mode    =    NORMAL_LONG_ET_MODE;
  //debug_printf("<<< pah8002_enter_normal_long_et_mode ir_dac %x, ir_expo %x\r\n", _ir_dac, _ir_expo);
  return   true;
RTN:  return false ;
}

static void pah8002_dyn_switch_ppg_mode() {
  uint8_t by2a4, by2a5 ;
  uint16_t value ;
  pah8002_wakeup();
  pah8002_write_reg(0x7F, 0x02);
  pah8002_read_reg(0xa4, &by2a4);
  pah8002_read_reg(0xa5, &by2a5);
  value = by2a5 ;
  value <<= 8 ;
  value += by2a4 ;
  if (value >  4639)               {
    pah8002_enter_normal_long_et_mode();
  }
}

//---------------------------------------PAH8002 functions-----------------------------------------------

bool pah8002_init(void) {

  uint8_t ret = 0;
  uint32_t open_size = 0;
  //Algorithm               initialization
  _pah8002_data.frame_count = 0 ;
  _pah8002_data.nf_ppg_channel  = TOTAL_CHANNELS_FOR_ALG;
  _pah8002_data.nf_ppg_per_channel = HEART_RATE_MODE_SAMPLES_PER_CH_READ;
  _pah8002_data.ppg_data = (int32_t *)pah8002_ppg_data;
#ifdef MEMS_ZERO
  memset(_mems_data, 0, sizeof(_mems_data));
  _pah8002_data.nf_mems = HEART_RATE_MODE_SAMPLES_PER_CH_READ;
  _pah8002_data.mems_data  =  _mems_data;
#endif
  open_size = pah8series_query_open_size();
  _pah8002_alg_buffer = malloc(open_size);
  ret  = pah8series_open(_pah8002_alg_buffer);
  if (ret != MSG_SUCCESS)   return false; // Set 0: +/-2G, 1: +/-4G, 2: +/-8G, 3: +/-16G
  if (MSG_SUCCESS != pah8series_set_param(PAH8SERIES_PARAM_IDX_GSENSOR_MODE, 1))      return false;
  //log_printf("PPG CH#, %d\n", TOTAL_CHANNELS_FOR_ALG);
  delay(300);
#ifdef PPG_MODE_ONLY
  return pah8002_enter_normal_mode();
#else
  return pah8002_enter_touch_mode();
#endif
}

void pah8002_deinit(void) {
  pah8002_enter_suspend_mode();
  pah8series_close();
  if  (_pah8002_alg_buffer)  {
    free(_pah8002_alg_buffer);
    _pah8002_alg_buffer  =    NULL;
  }
}


 void pah8002_log(void) {
  int i = 0 ;
  uint32_t *ppg_data = (uint32_t *)_pah8002_data.ppg_data ;
  int16_t *mems_data = _pah8002_data.mems_data ;
  //log_printf("Frame Count, %d \n", _pah8002_data.frame_count);
  //log_printf("Time, %d \n", _pah8002_data.time);
  //log_printf("PPG, %d, %d, ", _pah8002_data.touch_flag, _pah8002_data.nf_ppg_per_channel);
  for (i = 0; i < _pah8002_data.nf_ppg_channel  * _pah8002_data.nf_ppg_per_channel; i++)  {
    //log_printf("%d, ", *ppg_data);
    ppg_data ++;
  }
  //log_printf("\n");
  //log_printf("MEMS, %d, ", _pah8002_data.nf_mems);
  for (i = 0; i < _pah8002_data.nf_mems * 3; i++) {
    //log_printf("%d, ",  *mems_data);
    mems_data ++;
  }
  //log_printf("\n");
}

static void data_convert_4ch_to_3ch(uint32_t *pdata, uint32_t len) {
  uint32_t i = 0, j = 0;
  for (i = 0, j = 2; j < len; i += 3, j += 4)  {
    *(pdata + i + 1)   =  *(pdata + j);
    *(pdata + i + 2) =  *(pdata + j + 1);
  }
}

 void pah8002_task(void) {
  uint8_t   ret;
  float hr = 0 ;
  uint32_t  sys_tick;
  if (_pah8002_interrupt == 1)  {
    _pah8002_interrupt   =   0;
    if (_mode  == TOUCH_MODE)  {
      pah8002_enter_normal_mode();
      _timestamp = millis();
      //accelerometer_start();
    } else if (_mode == NORMAL_MODE || _mode == NORMAL_LONG_ET_MODE) {
      _pah8002_task();
      pah8002_dyn_switch_ppg_mode();

#ifdef PPG_MODE_ONLY

#else
      if (_touch_flag  ==  0)  {
        pah8002_enter_touch_mode();
        //accelerometer_stop();
      }
#endif
      //process algorithm
#ifdef MEMS_ZERO
#else
      //accelerometer_get_fifo(&_pah8002_data.mems_data, &_pah8002_data.nf_mems);
#endif
      sys_tick = millis();
      _pah8002_data.time = sys_tick - _timestamp;
      _timestamp  =  sys_tick;
      _pah8002_data.touch_flag =  _touch_flag;
      data_convert_4ch_to_3ch((uint32_t  *)pah8002_ppg_data,  HEART_RATE_MODE_SAMPLES_PER_READ);
      // log 3ch   ppg_data  before pah8002_entrance()
      pah8002_log();
      ret  =   pah8series_entrance(&_pah8002_data);
      if ((ret & 0x0f) != 0)    {
        switch (ret) //check error status
        { case MSG_ALG_NOT_OPEN:
            //debug_printf("Algorithm is not initialized.\r\n");
            break;
          case MSG_MEMS_LEN_TOO_SHORT:
            //debug_printf("MEMS data   length is  shorter than PPG data  length.\r\n");
            break;
          case MSG_NO_TOUCH:
            //debug_printf("PPG  is    no touch.\r\n");
            break;
          case MSG_PPG_LEN_TOO_SHORT:
            //debug_printf("PPGdata  length   is  too  short.\r\n");
            break;
          case MSG_FRAME_LOSS:
            //debug_printf("Frame  count   is  not  continuous.\r\n");
            break;
        }
      }
      if ((ret & 0xf0) == MSG_HR_READY)    {
        pah8series_get_hr(&hr)               ;
        //debug_printf("HR  =  %d\r\n",  (int)(hr));
//        display.setCursor(10, 40);
//  display.setTextColor(LCD_COLOR_BLACK);
//  display.setTextSize(2);
//  display.print("HR: ");
//  display.print(hr);
//  display.refresh();
      }
      _pah8002_data.frame_count++;
    }
  }
}

 void pah8002_intr_isr(void) {
  _pah8002_interrupt = 1 ;
}

//pah8002_comm_i2c.c


uint8_t pah8002_write_reg(uint8_t addr, uint8_t data) {
  //return i2c_write_reg(I2C_ID_PAH8002, addr, data);
  Wire.beginTransmission(I2C_ID_PAH8002);
  Wire.write(addr);
  Wire.write(data);
  Wire.endTransmission();
  return 1;
}

uint8_t pah8002_read_reg(uint8_t addr, uint8_t *data) {
  //return i2c_read_reg(I2C_ID_PAH8002, addr, data);
  Wire.beginTransmission(I2C_ID_PAH8002);
  Wire.write(addr);
  Wire.endTransmission();
  Wire.requestFrom(I2C_ID_PAH8002, 1);
  int intData = Wire.read();
  uint8_t byteData =lowByte(intData);
 data=&byteData;
  return 1;
}

uint8_t pah8002_burst_read_reg(uint8_t addr, uint8_t *data, uint32_t rx_size) {
  //return   i2c_burst_read_reg(I2C_ID_PAH8002, addr, data, rx_size);

  Wire.beginTransmission(I2C_ID_PAH8002);
  Wire.write(addr);
  Wire.endTransmission();

  Wire.requestFrom(I2C_ID_PAH8002, rx_size);

  int i = 0;
  while (Wire.available() && i < rx_size) {
    data[i] = Wire.read();
//    int intData = Wire.read();
//  uint8_t byteData =highByte(intData);
// data[i]=&byteData;
    i++;
  }

  if (i != rx_size) return 0; else return 1; //success or failure
  return 1;

}
