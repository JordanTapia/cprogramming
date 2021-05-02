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
 * @file stats.h 
 * @brief  Contains functionnality to calculate max, min, mean of an array of numbers.
 * 
 * @author Jordan Tapia 
 * @date 24 October 2020
 *
*/


#ifndef __STATS_H__
#define __STATS_H__


/* Add Your Declarations and Function Comments here */ 

/*********************************************************************************************** 
 * Function: find__mean
 * Description:
 * 	This function finds average of the set
 * Parameters:
 * 	unsigned char * test: Pointer to a data set
 * 	int size: Number of items in data set
 * Return:
 * 	Mean of data set
 ***********************************************************************************************/
int find_mean( unsigned char *test, int size );

/*********************************************************************************************** 
 * Function: find_maximum
 * Description:
 * 	This function finds max of the set
 * Parameters:
 * 	unsigned char * test: Pointer to a data set
 * 	int size: Number of items in data set
 * Return:
 * 	Max of data set
 ***********************************************************************************************/
int find_maximum( unsigned char *test, int size );


/*********************************************************************************************** 
 * Function: find_minimum
 * Description:
 * 	This function finds minof the set
 * Parameters:
 * 	unsigned char * test: Pointer to a data set
 * 	int size: Number of items in data set
 * Return:
 * 	Min of data set
 ***********************************************************************************************/
int find_minimum( unsigned char *test, int size );



/*********************************************************************************************** 
 * Function: sort_array 
 * Description:
 * 	This function sorts array from largest to smallest. 
 * Parameters:
 * 	unsigned char * test: Pointer to a data set
 * 	int size: Number of items in data set
 * Return:
 *	Void
 ***********************************************************************************************/
int sort_array( unsigned char *test, int size );


/*********************************************************************************************** 
 * Function: find_median 
 * Description:
 * 	This function finds median of a set of numbers 
 * Parameters:
 * 	unsigned char * test: Pointer to a data set
 * 	int size: Number of items in data set
 * Return:
 * 	Median of a set of numbers
 ***********************************************************************************************/
int find_median( unsigned char *test, int size );

void print_array( unsigned char *num, int len );

#endif /* __STATS_H__ */
