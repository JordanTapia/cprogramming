#include "data.h"

/* Convert int to string */
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base){
	uint8_t negative = 0;
	if(data < 0){
		data = data * -1;
		negative = 1;
	}
		if(data == 0){
		ptr = 0;
		return 0;
	}

	uint8_t digit;
	uint8_t count = 0;

	int32_t length = 1;
	while (length < data){
		length = length * base;
		count = count + 1;
	}

	uint8_t offset = 0;
	if (negative){
		offset = 1;
	}
	uint8_t size = count + offset;
		ptr[count + offset] = '\0';

	while(data > 0){
		digit = data % base;
		if (digit > 9){
			digit = digit + 48 + 17;
		}else{
			digit = digit + 48;
		}
		ptr[count - 1 + offset] = digit;
		count = count - 1;
		data = data / base;
	
	}
	if (negative){
		ptr[0] = '-';
	}

	return  size;
}
/* Convert string to int */
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base){
	int32_t num = 0;
	uint32_t base_copy = 1;
	for (int i = digits - 1; i >=0; i--){
		if ( ptr[i] == '-'){
			num = num * -1;
		} else {
			num = num + (ptr[i]-48) * base_copy;
			base_copy = base_copy * base;
		}
	}
	return  num;
}
