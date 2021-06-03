#include <stdint.h>
#include "miros.h"
#include "bsp.h"

uint32_t stack_blinky1[40];
OSThread blinky1;
void main_blinky1(){
	while(1) {

	}
}

uint32_t stack_blinky2[40];
OSThread blinky2;
void main_blinky2(){
	while(1) {

	}
}

int main() {
	BSP_init();

	/* fabricate Cortex-M ISR stack frame for blinky 1 */
	OSThread_start(&blinky1,
				   &main_blinky1,
				   stack_blinky1, sizeof(stack_blinky1));

	/* fabricate Cortex-M ISR stack frame for blinky 2 */
	OSThread_start(&blinky1,
				   &main_blinky1,
				   stack_blinky1, sizeof(stack_blinky1));
}