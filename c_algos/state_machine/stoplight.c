/*
   
   State machine tutorial from:
   https://stackoverflow.com/questions/1371460/state-machines-tutorials

   @enum state_codes
   @enum ret_codes

- To Do:
- (skeletal) code all the functions <entry/foo/bar/exit>_state
- (only tested the 'ok' result ) test some input, including exit state
- (DONE) printf statements for src, ret, dst output 
- 
- NOTES:
- relies on state to produce a ret code, i.e. an 'event'
- how to do similar with outside input for event, i.e. a timer or push button? 
-
- Stretch Goal:
- implement this on MSP432 with some LEDs 
- state machine for regex matching
- 
- Side goal:
- something with dB calculation since I want to become better with that
- 
- CMSIS? 
- MISRA
- Lint
- Doxygen: documentation generator
-
- My Website
*/

#include <assert.h>
#include <stdint.h>
#include <stdio.h>


enum state_codes { red, yellow, green, fault};
enum ret_codes { timer, button_ped, fault};

int red_state(void){
  return timer;
}

int yellow_state(void){
  return timer;
}

int green_state(void){
  return timer;
}

//array of function pointers
int (* state[])(void) = { red_state, yellow_state, green_state};

/*
   state[0]->address of entry_state()
   state[1]->foo_state()
   .
   .
   //the function pointer seems to 'add' the right structure
*/


//transition is 3 enum struct (probably for small memory footprint
// { src state, return code, destination state }
struct transition {
   enum state_codes src_state;
   enum ret_codes ret_code;
   enum state_codes dst_state;
};


//struct transition poo;
//printf("size of struct transition:\n");
//an array of struct transition 
//enum is 32 bit = 4 bytes
//8*4 = 32 bytes = struct size
//sizeof returns 96
struct transition state_transitions[] = {
    {entry, ok,     foo},
    {entry, fail,   end},
    {foo,   ok,     bar},
    {foo,   fail,   end},
    {foo,   repeat, foo},
    {bar,   ok,     end},
    {bar,   fail,   end},
    {bar,   repeat, foo}
    };

uint32_t state_machine_size = sizeof(state_transitions);//= size of transition * num transitions in state transitions[]

#define EXIT_STATE end
#define ENTRY_STATE entry

int lookup_transitions(cur_state, rc){

   //int size_states = 8;
   // printf("size of states: %lu\n", sizeof(state_transitions));//change from hard-coded

   for(int i = 0; i < state_machine_size; i++){

      if(state_transitions[i].src_state == cur_state && state_transitions[i].ret_code == rc){
         return state_transitions[i].dst_state;
      }
   }
   return 0;
}


int main () {
	
   //lookup table needed
   enum state_codes cur_state = entry;
   enum ret_codes rc;

   int (*state_fun)(void); //this is interesting. out of nowhere...a function pointer!

   //struct transition tx1;
   //printf("size of transitions struct: %lu\n", sizeof(tx1));


   for(int i = 0; i < 8; i++){
      printf("%d ", state_transitions[i].src_state);
      printf("%d ", state_transitions[i].ret_code);
      printf("%d ", state_transitions[i].dst_state);
      printf("\n");
   }

   for (int j = 0; j < 20; j++) {
        state_fun = state[cur_state];//set function pointer to call state_fun()
        rc = state_fun();
        //return code will depend on how function executes
        if (EXIT_STATE == cur_state)
            break;
        cur_state = lookup_transitions(cur_state, rc);
    }

   printf("bye, now!\n");
   return(0);
}