#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>


/*
	VIDEO 1 

	Advanced Pointers
	Peripheral:  External to CPU specialized support hardware. 
	Inline and macro functions. 
	Function pointers dynamically change
	We'll blink an LED, eventually.
*/

/* 
	VIDEO 2

	Bitwise operators
	Bitmasks defined in header files 
	Bit band alias: a way ARM gives to access a single bit fast,
	The bit is aliased to a whole byte in first MB of SRAM or Peripheral, 
	and accessed (fast) via pointer. This read/write is done in a single instruction,
	so it is atomic and won't corrupt anything. 


	VIDEO 3

	Toggle a port pin! MSP432 has 8 pins per port and 10 ports!
	To do: read thru Configuring IO on technical ref man.
	Code composer stucio CCS from TI

	Video 4 

	Create a HAL: like an API to higher-level SW
	Compile time switches may be used to make this portable
	RDF's, macros, specialized c-functions
	Arm CMSIS: std if with diff arch
	RDF: 
		Provide address lists, access methods, Defines for Bit Fields/Masks. How to abstract?
	Use Macro Functions:
		Lots of macros that:
			set register address
			configure
		This baby has no overhead! No function call!
			#define HWREG8(x) (*((volatile uint8_t *)(x));
			#define TAOCTL (HWREG16)
			HWREG16(TA0CTL_ADDR) = 0x0202;

				different ways of doing the same thing:
			1):
			define HWREG16(x) (*((volatile uint16_t *)(x));
			HWREG16(TA0CTL_ADDR) = 0x0202;
			2):	
			#define TAOCTL (HWREG16(0x40000000))
			TAOCTL = 0X0202;


	Use spec c- funcs:
		inline
		static

*/
int main(){

	uint8_t * ptr = (uint8_t *)0x1000;

	printf("%x\n", ptr);

	int x = 5;
	int * ptr2 = x;
	printf("%x\n", ptr2);

	uint8_t foo = 0xff;
	foo &= ~(0xc0);
	printf("%x\n", foo);	


			


	return 0;
}
