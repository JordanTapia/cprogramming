#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdint.h>
#include <stdbool.h>

#define INTMAX =  2147483647
#define INTMIN = -2147483648

bool isPalindrome(int x){
    
    if(x < 0)
    {
        return 0;
    }
    
    int nums[10] = {0};
    int numsSize = 0;
    while(x != 0)
    {
     int pop = x % 10;
     nums[numsSize++] = pop;
     x = x / 10;
    }
    for(int i = 0; i < numsSize/2; i++)
    {
    	if(nums[i] != nums[numsSize - i - 1])
    	{
    		return false;
    	}
    }
    return true;

    
}

int main(){
	int x[5] =  { 123, 545, 0, -1, 12321 };
	for( int i = 0; i < 5; i++)
	{
		printf("%d: %d\n", x[i], isPalindrome(x[i]));
	}
}