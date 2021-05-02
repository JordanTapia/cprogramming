#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define MAXSIZE 100
int main(){

	// FILE *fp = fopen("capitols_file", "r");
	// char *fgets(char *line, int maxline, FILE *fp)
	// int fputs(char *line, FILE *fp)

	char * b;
	size_t bufsize = MAXSIZE;														
	//printf("typesomething\n");

	// return int = size
	FILE *fp = fopen("capitols.txt", "r");
	size_t lineSize;
	while((lineSize = getline(&b, &bufsize, fp)) != -1){             //getline on EOF returns -1

		char * token = strtok(b, ", ");

		char * token2 = strtok(NULL, "\n");

		//printf("%s", b);
		//printf("line size: %lu\n", lineSize);

		//char *strtok(char *str, const char *delim)
		//split b by ',' space and '\n'

		//tokenize

	}

	return 0;
}