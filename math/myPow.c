#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>


double myPow(double x, int n){

	double ans = 1;
	double x_base = x;
	int isNeg = 0;

	if(n == 0) {
		return ans;
	}

	if(n < 0) {
		n = -1 * (n + 1);
		isNeg = 1;


	}

    while(n) {
        
        printf("%x\n", n);//////

        if(n & 1U) {
        	ans = ans * x_base;
        }
        n = n >> 1;
        x_base = x_base * x_base;


    }

    if(isNeg) {
    	ans = 1 / (ans * x);
    }

    return ans;
}



int main() {

	int y = 3;
	int n = -3;
	int x = myPow(y, n);
	printf("myPow(%d, %d) = %d\n", y, n, x);
	return 0;
}

/*

2 ^ 001011 =      2^11
2^1 * 2^10 =      2^11
2^1 * 2^2 * 2^8 = 2^11


         -2^31 <= n <= 2^31 - 1
-2,147,483,658 <= n <= 2,147,483, 647



*/