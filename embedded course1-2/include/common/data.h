#ifndef __DATA_H__
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#define __DATA_H__

/* Convert int to ASCII string */
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);

/* Convert ASCII string to int */
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);
#endif