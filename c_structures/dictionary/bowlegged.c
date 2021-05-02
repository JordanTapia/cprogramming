#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>


void removeFirstWhiteSpace(char str[]){
	if( str[0] == ' ' ) {

		printf("conditional\n");

		for(int i = 0; str[i] != '\0'; i++){
			str[i] = str[i+1];
		}
	} return;
}

int main(){

	char str[20] = "hello, world\0";
	char * token1 = strtok(str, ",");
	char * token2 = strtok(NULL, "\0");	 


	printf("%c %c\n", str[0], str[1]);////////

	removeFirstWhiteSpace(token1);
	removeFirstWhiteSpace(token2);

	printf("%s\n%s\n", token1, token2);
	return 0;
}