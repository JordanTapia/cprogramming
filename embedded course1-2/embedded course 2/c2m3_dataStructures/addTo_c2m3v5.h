#include <stdio.h>
#include <stdint.h>
/*
############################# Circular Buffer ############################
	// Note this should be combined with c2m3v5.h from other machine.
	

	Buffer usage case:

		Buff_add() ---> [ SW Buffer ] ---> Buf_remove() ---> [ UART Reg	]
	
		FIFO used for this, adds to head, removes from tail, 
		when reaches end of allocated memory, head returns to tail.

*/

/*
	a circular buffer implementation
	head, base tail, pointers that define data type uint8_t
	length and count are 1 word
*/
typedef struct {
	uint8_t * base
	* head
	* tail
	uint32_t length
	count
} CB_t;

//example code 
CB_t * buf = Buffer_init(5);
Buffer_add(&buf, 0xFF);
Buffer_rem(&buf, &item);

/*
############################# Circ Buffer FULLNESS ############################
*/


typedef enum {

	CB_NOT_FULL
	//other flags, warnings, etc.

} CB_Status;



/*
	@ function -> returns a typedef enum full of flags 0-7 
	@ return   -> enum CB_Status of flags
	@ param	   -> buffer type struct 
*/
CB_Status CB_Is_Buffer_FULL (CB_t * cbuf){

	//check all valid ptrs
	if( ! cbuf || ! head || !tail || !base ) {
		return CB_NULL;
	}
	//check tail relative to head
	//check head relative to tail + length
	//more complicated because there are 2 moving poointers (not like LIFO base)
	if (   ){

	}

}


CBstatus CB_add_item (CB * cbuf, uint8_t item){
	chekc valid ptr
}






/*
############################# Linked List ############################

Buffer's need a contiguous mem allocation. May not have enough

LL's can be scattered randomly in memory, yet are contiguous in order

Nodes indep allocated 

Can a buff be implemented in LL? 

*/

//typedef used, but first defined Node_t and node 
typedef struct {
	Node_t * next;
	uint32_t data;
} Node_t; 



//typedef node defined
typedef struct node {
	struct node * next;
	uint32_t data;
} Node_t;

//node defined
struct node { 
	struct node * next; 
	uint32_t data;
};




