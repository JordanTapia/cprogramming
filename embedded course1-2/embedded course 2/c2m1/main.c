





#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "endianness.h"



/*
	Helper function to print a number in binary format. 
	@param num: a 32 bit unsigned
*/
void print_bin(uint32_t * num){
	uint32_t a = *num;
	uint32_t bit_mask = 1 << (sizeof(a)*8-1);
	printf("print_bin a: 0x%x\n",a);
	printf("bitmask: %x\n", bit_mask);

	for(int i =0; i < sizeof(a)*8; i++){
		printf("%u", a&bit_mask ? 1 : 0);
		a = a << 1;
	}
	printf("\n");
	return;
}

int main(){

	/*
	Dereferences 16 bits of data starting at 0x200 and interprets it as unsigned.
	Below 0x200 is cast as a pointer
		example:
	uint8_t ptr2 = (uint8_t*)ptr1; 
	*/
	int * ptr2=0;
	*ptr2 = 7;

	uint32_t i = 0x3456;
	uint32_t * ptr = &i;
	printf("ptr: %x\n", (uint32_t)ptr);
	printf("address of ptr: %x\n", (uint32_t) &ptr);
	printf("ptr_data: %d\n", (uint32_t)*ptr);
	/*
	Dereference * 
	Address of &. Use to initialie a pointer
	int foo;
	int * ptr = &foo;
	struct ptr
	varS-ptr->varB. Works the same as a dereference operator, but for struct
	int ptr1 = (int*)0x100;
	//first byte only, recast
	uint8_t ptr2 = (uint8_t*)ptr1; 
	*/


	//__attribute__((always_inline)) inline 
	//printf("*ptr: %b\n", *ptr);
	print_bin(ptr);
	printf("*ptr: 0x%x\n", *ptr);
	swapend(ptr);
	printf("*ptr swapped: 0x%x\n", *ptr);
	/* 
	word aligned is most efficient for our CPu to operate on
	or aligh by 2,4, 8, 16 bytes
		example:
	place at word aligned address
	int8_t foo __attribute__ ((aligned(4))) 
	*/

	/*
	Two different ways for ligned struct
		example:
	*/
	typedef struct {
		int8_t krunk __attribute__((aligned(4)));
		int16_t krunk2 __attribute__((aligned(4)));
	} dexter;
		
	typedef struct {
		int8_t krunk3;
		int16_t krunk4;
	} dexter2 __attribute__((aligned(16)));//or packed


//##//########################### Register Definition Files ###########################################################################################
	/*
	register definition file to make code portable 
	thousands of peripheral regs
	use pointers to...
	assign value to timer a0 address = 0x40000000 
		
		example:
	volatile uint16_t * ta0_ctrl = (uint16_t*)0x40000000;
	*ta0_ctrl=0x0202;
	*/

//############################# Macro function example ###########################################################################################
	/*
	instead of using thousands of pointer variables
	bypasses the need for pointer variable
	(dereference(cast as volatile ptr)(addr))=value;
		
		example:
	(*((volatile uint16_t *)0x4000000)) = 0x0202;
	*/

	/*
	Use macros to make th≥¯˘≥is stuff portable.
v	Macro for the pointer dereference function...
	and a macro outside that for each register
	use compile time switch for diff versions of same HW
	or diff arch...etc.
		
		example: 
	#define HWREG8(x) (*((volatile uint8_t *)(x));
	(x is byte address)
	*/


//############################# Struct overlay example ###########################################################################################



	/*
	structure overlays to do the same thing
	then all the addresses don't necessarily need to be known 
	if you know ther first base offset
		
		example:
	#define __IO(volatile)
	#define __I (volatile const)
	typedef struct{
		__IO uint16_t CTL;
	}Timer_A_Type;
	*/


	return 0;
}
