/*
Course 2 Video 5

Advanced Pointer Use

*/

############################# void pointer #######################################################################################


/*
	imagine a data structure passed between 2 systems over UART...we don't know the \
	type. This could?  be scenario where void pointer needed. 
*/
//size of a word on our 32 bit system (4 bytes)
//to store an address
sizeof(void*) = sizeof(uint32_t*)	
//cast it before interacting witht hte underlying memory
void * ptr1 = (void*)0x40000000;
//ptr1 = 0x0202		
*((uint16_t*)ptr1)) = 0x0202;
//no pointer arithmetic

//malloc returns a void pointer that you cast 
char * ptr;
ptr = (char *)malloc(8*sizeof(char));
if(ptr==NULL){
	/*FAILED*/
}
/*OTHER CODE*/
free((void *)ptr); 




############################# double pointer #######################################################################################
//useful when developers need to set the value of pointer itself, i.e. the address, then pass to function
//pointer to a pointer
//allow us to change the address a pointer holds
uint32_t var = 0x1234abcd;
uint32_t * ptr3 = &var;
uint32_t ** ptr4 = &ptr3; //double pointer

/*can pass this to a function, which makes a copy, then the function can change  \
	the value that original was pointed at. 
	The original pointer may now point to some data that wasa modified by func, but
	its address remains unchanged. 
*/

/*
	Ther below demonstrates passing double pointer to be copied and modified. The data it points to 
	is mod'd by function, in this case malloc'd memory. Then the pointer external to function modified the data.
*/
typedef enum {
	RSP_TYPE_1 = 0,
	RSP_TYPE_2 = 1,
} RSP_e;

typedef struct {
	RSP_e rsp_type;
	uint8_t data[4];
} rsp1; 

int8_t create_rsp1 (rsp1 ** r_p){
	*r_p = (rsp1 *)malloc(sizeof(rsp1)); //data of rp is allocated memory of type rsp1. this has 2 dereferenced ptrs!

	if (r*p == NULL) {					 //check malloc worked
										 //malloc failed
		return -1;
	}
	(*r_p)->rsp_type = RSP_TYPE_1;		 //initialize: data that r_p points to gets initialized. \
										   I think it's a sneaky way of not needlessly allocating stuff \
										   and waiting for malloc. 
	return 0;
}






############################# restrict pointer #######################################################################################

uint32_t * restrict ptr4;

this memory is not overlapped or aliased, ok to optimize memory interaction














