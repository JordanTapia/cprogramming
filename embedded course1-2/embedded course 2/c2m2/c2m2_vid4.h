/*
Course 2 Video 4

Covers portability to different platforms using macros, specialized c-functions, and ending		\
	with an example of a Hardware Abstraction Layer to 2 different platforms that will blink	\
	the LED

*/

############################# Port Macros 1 #######################################################################################

#DEFINE HWREG(8)	(*((volatile uint8_t *)(x)))	// an 8 bit dereferenced pointer to address x

/* Port 1 Register Access Macros */
#define P1DIR (HWREG8(0X40004C00)) 					// a macro within a macro

/* Set P1.0 to Output Direction */
P1DIR |= 0x01;										// again





############################# Port Macros 2 #######################################################################################

//struct method

#define __IO(volatile)
#define __I (volatile const)


//a bit confusing, mightbe some typos

 // See C2V4


############################# Bit band macros #######################################################################################

/*
	Parts of sram and peripheral memory have bits mapped to complete words, allowing atomic operation to a single bit.
	Exampe first bitof address 0x00000010 is 4 bytes, but it aliases to another memory location from which we can use 
	a pointer, i.e. not declare shit, have no overhead of read/modify/write, and do shit atomically (safely?). 

	basically, its a faster to read/write a bit
*/

 
 // See 5:31 of C2V4


############################# Specialized C- functions #######################################################################################

__attritube__((always_inline)) inline					//no calling, like copy paste \
														inline = c99, attribute always inline = gcc


__attritube__((always_inline)) inline int 32_t add(int x, int y){
	return( x + y );
}




############################# Specialized C- functions : inline and static #######################################################################################


inline good because type checking
static -> private
local
also global and variables only visible to current file -> a translation unit -> all linking internal
static + inline prevents compiler from integrating all the code of calling n shit into the function. assumes \
	all linkage is internal


############################# LED example of Portability #######################################################################################

/*
	platform.c/h contained compile time switch for <MSP/KLZ>.h
	regdef file, macros, special c-funcs contained in MSP/KL/z.h to interface to HW and registers
*/