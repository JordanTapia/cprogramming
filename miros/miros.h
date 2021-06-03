#ifndef MIROS_H
#define MIROS_H

/*Thread Control Block (TCB) */
typedef struct {
	void *sp;
} OSThread;

typedef void (*OSThreadHandler)();

void OS_init(void); // NVIC_SetPriority(SysTick_IRQn, (U)); a CMSIS function for raising SysTick priority
					// set in startup code. I think PendSV should be lowest priority?

void OS_sched(void);

void OSThread_start(
	OSThread *me,					 // not sure why two stack pointers needed? One is OSThread*, other is void *.
	OSThreadHandler threadHandler,	 // function pointer to OSThreadHandler
	void *stkSto, uint32_t stkSize);  // memory for the private stack and size of stack 


#endif