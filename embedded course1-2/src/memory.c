/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file memory.c
 * @brief Abstraction of memory read and write operations
 *
 * This implementation file provides an abstraction of reading and
 * writing to memory via function calls. There is also a globally
 * allocated buffer array used for manipulation.
 *
 * @author Alex Fosdick
 * @date April 1 2017
 *
 */
#include "memory.h"




/***********************************************************
 Function Definitions
***********************************************************/
void set_value(char * ptr, unsigned int index, char value){
  ptr[index] = value;
}

void clear_value(char * ptr, unsigned int index){
  set_value(ptr, index, 0);
}

char get_value(char * ptr, unsigned int index){
  return ptr[index];
}

void set_all(char * ptr, char value, unsigned int size){
  unsigned int i;
  for(i = 0; i < size; i++) {
    set_value(ptr, i, value);
  }
}

void clear_all(char * ptr, unsigned int size){
  set_all(ptr, 0, size);
}

void free_words(uint32_t * src){
	free(src);
	return;
}

int32_t * reserve_words(size_t length){
	return (int32_t *) malloc(length * 4);
}

uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length){
	if(src < dst && src + length >= dst) {
		int32_t * temp;
		temp = reserve_words(length);
		for (uint8_t i = 0; i < length; i++){
			*(temp + i) = *(src +i);
		}	
		for (uint8_t j = 0; j < length; j++){
			*(dst + j) = *(temp + j);
		}
		free(temp);
	} else {
		
		for(int k = 0; k < length; k++){
			*(dst + k) = *(src + k);
		}
	}
	return dst;
}

uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length){
	for(int i = 0; i < length;i++){
		*(dst + i) = *(src + i);
	}
	return dst;
}

uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value){
	for (int i = 0; i < length; i++){
		*(src + i) = value;
		//printf("%u\n", *(src+i));
	}
	uint8_t * ptr = src;
	return ptr;
}

uint8_t * my_memzero(uint8_t * src, size_t length){
	for (int i = 0; i < length; i++){
		*(src + i) = 0;
	}
	uint8_t * ptr = src;
	return ptr;
}

uint8_t * my_reverse(uint8_t * src, size_t length){
	uint8_t last = length - 1;
	uint8_t temp = 0;
	for (int i = 0; i < last; i ++){
		temp = *(src + i);
		*(src + i) = *(src  + last);
		*(src  + last) = temp; 
		last = last - 1;		
	}
	return src;
}
