#include <stdint.h>
#include <stdio.h>
#include "endianness.h"

void swapend (uint32_t * ptr){

	int size = sizeof(*ptr);
	char * head =(char *)ptr;
	char * tail = head +  size -1;
	printf("size %d\n",size);
	char temp;

	for (int i = 0; i < size/2; i++){
		temp = *head;
		*head = *tail;
		*tail = temp;
		head++;
		tail--;
	}
	
	return;
}

