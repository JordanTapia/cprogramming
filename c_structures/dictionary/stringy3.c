#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 100
int main(){

	char b[] = "hello";
	printf("%s\n", b);
	
	printf("%c\n", (b + 1));

	return 0;
}