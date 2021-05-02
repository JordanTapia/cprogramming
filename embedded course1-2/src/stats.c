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
/*
 * @file stats.c 
 *
 * Functions of this file return mean, max, min and median of an array of length SIZE. 
 * Also sorts array in descending order.
 *
 * @author Jordan Tapia
 * @date 24 October 2020
 *
 */



//#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

int find_mean( unsigned char *test, int size ){
	int total = 0;
	if ( test == '\0' ){
		return 0;
	}

	if ( size <= 0 ) {
		return 0;
	}

	for( int i = 0; i < size; i++ ){
		total = total + test[i];
	}
	return total / size;
}


int find_maximum( unsigned char *test, int size ){
	int max = 0;

	if ( test == '\0'){
		return 0;
	}

	if ( size <= 0 ) {
		return 0;
	}

	for( int i = 0; i < size; i++ ){

		if (test[i] > max) {
		max = test[i];
		}
	}
  return max;
}

int find_minimum( unsigned char *test, int size ){
	int min;

	if ( test == '\0' ){
		return 0;
	}

	if ( size <= 0 ) {
		return 0;
	}
		min = test[0];
	for( int i = 1; i < size; i++ ){

		if (test[i] < min) {
			min= test[i];
		}
	}
	return min;
}

int find_median( unsigned char *test, int size) {
if ( test == '\0' ){
		return 0;
	}
	else if ( size <= 0 ){
		return 0;
	}
	unsigned char temp[size];
	for( int i = 0; i < size; i++){
		temp[i] = test[i];
	}
	sort_array(temp, size);
	if( size %2 != 0 ){
		return temp[ size /2 + 1 ];
	}
	else{
		return (temp[ size/2  ] + temp[ size/2 + 1])/2;
	}
}


int sort_array( unsigned char *test, int size ){

	for ( int  i = 0; i < size - 1; i++) {

		for ( int j = 0; j < size - i - 1; j++ ){
			if ( test[j] < test[j +1] ){
				int temp = test[j];
				test[j] = test[j+1];
				test[j+1] = temp;
			}
		}
	}
	return 0;
}


void print_statistics( unsigned char *num, int len ){
/*
	printf("Max: %d\n", find_maximum(num, len) );
	printf("Min: %d\n", find_minimum(num, len) );
	printf("Median: %d\n", find_median(num, len) );
	printf("Mean: %d\n" , find_mean(num, len) );
*/
return;
}

/* Modified @print_array() to add compile time switch on -DVERBOSE */
void print_array( unsigned char *num, int len ){
	#ifdef VERBOSE
/*
		for (int i = 0; i < len; i++) {

			if (i == 0){
				printf("[ %d," , num[i] );
			}
			else if ( i == len -1 ){
				printf(" %d ]\n" , num[i]);
			}
			else {
				printf( " %d," , num[i]  );
			}
		}
		return;
*/
	#endif
	return;
} 
