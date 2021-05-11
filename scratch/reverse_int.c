#include <stdlib.h>
#include <stdio.h>

#define MAXDIGITS 10




int power(int x, int y)
{
    if( y == 0)
    {
        return 1;
    }
    else if(y == 1)
    {
        return x;
    }
    else
    {
        return (x * power(x, y - 1));
    }
}

int reverse(int x)
{
    int num = x;
    int digits[MAXDIGITS] = {0};
    int size = 0;
    int ans = 0;
    for(; num != 0; size++)
    {
        digits[size] = num %10;
        //printf("%d\n", digits[size]);///////////////
        num = num / 10;
    }
    //printf("size: %d\n", size);///////////////
    int maxpos = 2147483648 -1;
    int maxneg = -2147483648;

    for(int i = size; i > 0; i--)
    {
        if( ans >= 147483647 && digits[i-1] >= 2 )
        {   
                return 0;
        }
        if( ans >= (maxpos)/10 && (digits[i-1] != 0)  )
        {
            return 0;
        }

        if( ans <= -147483648 && digits[i-1] <= 2 )
        {   
                return 0;
        }
        if ( ans <= maxneg/10 && (digits[i-1] != 0) )
        {
            return 0;
        }
        ans = ans + digits[i - 1] * power(10, size - i);
    }
    //2,147,483,648 - 1
    //2,147,483,648

    return ans;
    

}



int main(){
    int x = 1563847412;
    //int y = 3646324351;
	printf("%d, %d\n", x, reverse(x));

}