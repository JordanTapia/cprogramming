
#include <everything.h>

/*

	Function Pointer

Dereferencing a function pointer will call/execute code  
Points to code in code memory

Requirements:
	init and asgn to func * needs matching
		1) return type
		2) param list

Good to have's:
		1) good idea to use typedef 
		2) fptr array

Declaration:
	<type>(*<function_ptr_name>)(<paramater list>) = <function-address>;

*/



############################# fptr declaration #######################################################################################

/* Function Bar Prototype */
int8_t bar();

/* Function Pointer example */
int8_t (*foo)()= &bar;

############################# fptr typedef #######################################################################################

typedef int(* fptr_TYPE)(int c, int d); //fptr_TYPE pointer to a func

/*Two fptr_TYPE pointer declarations */
fptr_TYPE fptr1 = &foo;
fptr_TYPE fptr1 = &bar;

############################# fptr array #######################################################################################
/*
	Spatially locate entry points to functions in an array 
	Usages:
		Statemachines, interrupts, API's
*/

typedef void (* FuncPtr_t[2])(); // typedef return-type, ptr name [ ], params

FuncPtr_t example =				 // an enum-lookin fptr array
{
	foo,
	bar
};
//////////////////////////OR this way...

typedef void (* FuncPtr_t)(); // typedef return-type, ptr name [ ], params

FuncPtr_t example[2] =				 // an enum-lookin fptr array
{
	foo,
	bar
};




############################# interrupt vector table #######################################################################################
//The interrupt vector table is an array of function pointers that are indexed according to priority .

/*

	an important use of function pointers
	INT's request CPU to stop compiling main and go to some other function
	ISR: interrupt serviice routing

	first section in our Code memory at 0x000

	its definition requires linker mapping and C/assembly code

	vector table defined for MSP432
		linker script data section called '.intvecs' associated with #pragma  

	
*/


#pragma DATA_SECTION(interruptVectors, ".intvecs") // intvecs gets associated with this function ptr array var
void (* const interruptVectors{})(void)			   // void pointer, const cuz we no wanna alter this array
{
	//first element is the initial stack pointer to initialize the core CPU registers
	/* 
		dont know how this works
		but you follow the pragma with the actual fptr * [] declaration


	*/
}


/*

	the above shit  is all type void functions. makes sense...interrupts aren't really needed by main, only cpu i guess

*/













































