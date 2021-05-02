#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
	Why does your code crash:

The reason is that by writing 9 chars (don't forget the trailing null byte) into an area sized for 4 chars, you will probably overwrite the administrative-data stored for another chunk of memory that resides "behind" your chunk of data (since this data is most often stored "in front" of the memory chunks). When free then tries to put your chunk into the free list, it can touch this administrative-data and therefore stumble over an overwritten pointer. This will crash the system.

This is a rather graceful behaviour. I have also seen situations where a runaway pointer somewhere has overwritten data in the memory-free-list and the system did not immediately crash but some subroutines later. Even in a system of medium complexity such problems can be really, really hard to debug! In the one case I was involved, it took us (a larger group of developers) several days to find the reason of the crash -- since it was in a totally different location than the one indicated by the memory dump. It is like a time-bomb. You know, your next "free" or "malloc" will crash, but you don't know why!

Those are some of the worst C/C++ problems, and one reason why pointers can be so problematic.

*/

int main() {
    unsigned char *p = (unsigned char*)malloc(4*sizeof(unsigned char));
    memset(p,0,4);
    strcpy((char*)p,"abcdabcd"); // **deliberately storing 8bytes**
    printf("%c\n", *p);
    free(p); // Obvious Crash, but I need how it works and why crash.
    for (int i = 0; i < 9; i++){
    	printf("%c", *(p+i));
    }
    printf("\n");
    return 0;
}
