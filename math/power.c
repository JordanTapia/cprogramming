#include <stdlib.h>
#include <stdio.h>

#define NMIN = -2147483648
#define NMAX = 2147483647

/*
double myPow(double x, int n){
    //printf("x: %f, n: %d\n", x, n);
    if(n == 0)
    {
        return 1;
    }
    else if(n == 1)
    {
        return x;
    }
    else if(n < 0)
    {
        return ((1/x) * myPow(x, n + 1));
    }
    else
    {
        return (x * myPow(x, n - 1));
    }
}
*/

double myPow(double x, int n) { 
    if(n==0)return 1;
    int origN=n;
    double origX=x;
    double res=1;
    if(n<0){
        // to prevent the overflow in case of -ve scenario
        n=-(n+1);
        //n = -n;
        x=1/x;
    }
    while(n){
        if(n&1)res=res*x;
        n>>=1;x=x*x;
    }
    return (origN<0)?res*(1/origX):res;
}



int main(){

    

    double x = 2;
    int n = -2;
    double ans = myPow(x, n);

    printf("myPow(%f, %d = %f)\n", x, n, ans);

}