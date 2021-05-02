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
    uint8_t *ptr1 = (uint8_t *)0x10; //ptr1 points to 8 bits worth of data at 0x10
    uint8_t **dptr = &ptr1; //dptr = address of ptr1 = 0x10
    uint8_t *ptr2 = **dptr; //*dptr = address of ptr1, **dptr = value ptr1 pointes to
    uint8_t foo = *ptr2;
    return 0;
}
