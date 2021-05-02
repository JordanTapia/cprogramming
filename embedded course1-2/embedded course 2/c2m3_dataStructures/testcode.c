// An example program to demonstrate working 
// of enum in C 
#include <stdio.h> 
#include <stdint.h>


enum week{Mon, Tue, Wed, Thur, Fri, Sat, Sun}; 

//node defined
struct node { 
	struct node * next;
	uint32_t data;
};

//typedef node defined
typedef struct {
	struct node * next;
	uint32_t data;
} Node_t;

int main() 
{ 
    enum week day; 
    day = Wed; 
    printf("%d\n",day); 
    return 0; 
} 