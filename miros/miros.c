#include <stdint.h>
#include "miros.h"

OSThread * volatile OS_curr; // ptr can change, needs to be volatile
OSThread * volatile OS_next;


/*
	// To Do
	// Become familiar with the PendSV for swittching context
	// It's in assembly, woohooo!
	// Why is it in assembly? How are registers pushed/popped
*/


void OS_init(void) {
	*(uint32_t volatile *)0xE000Ed20 = 0xFFU << 16;
}


void OS_sched(void){ // carefule of race conditions

	//how to switch context
	//call from systick handler after irq-s disabledd
	//probably uses some state machine to switch, will go over future lessons

}


void OSThread_start(
	OSThread *me,					 // not sure why two stack pointers needed? One is OSThread*, other is void *.
	OSThreadHandler threadHandler,	 // function pointer to OSThreadHandler
	void *stkSto, uint32_t stkSize)  // memory for the private stack and size of stack 

{
	uint32_t *sp = (uint32_t *)((((uint32_t)stkSto +stkSize) / 8) * 8); // start from the top. stack grows down
																		// 8-byte aligned
	*(--sp) = (1U << 24);				/* xPSR */
	*(--sp) = (uint32_t)&threadHandler;	/* PC 	*/
	/*
	. LR
	. R12
	. R3
	. R2
	.
	.
	. Need to use entire stack frame
	*/
 


	me->sp = sp; //stack frame built, now save top of stack frame into the sp member of your OSThread structure
	/*
	stk_limit

	pre-fill unused stack wiht 0xDEADBEEF	
	*/
}



void PendSV_Handler(void) {//bit28 of ICSR register to trigger PendSV, our ocntext switch
	// preempts even the systick, NOT what we want
	// want systick to complete, then switch to pendSV
	// use adjustable interrupt priorities at register SYSPRI3...these can be complicated

	// Miro does some assembly stuff here
	// Not sure what
	// but he used a trick where wrote a bunch of C
	// then copy pasted the generated assembly with '__asm' Keil command for compiler to use assembly 65


}


