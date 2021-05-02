
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "bst.h"

/*
// I want to remove leading spaces and trailing newlines from all words
// Can deal with leading nulls, spaces as well due to getline/strtok usage

void parse(char * str)
{
	int i = 0;
	while( strcmp(*(str + i), "\0") != 0)
	{
		printf("%c", (char)*(str + i));
	}
}
*/

int main(){

	/*
	char *list[MAXSIZE] = {
	"red",
	"orange",
	"yellow",
	"green",
	"blue",
	"indigo",
	"violet"
	};
	*/
	struct tnode *root;
	root = NULL;

	/* char *fgets(char *str, int n, FILE *stream) */




	char * b;
	size_t bufsize = 100;														
	FILE *fp = fopen("input.txt", "r");

	if(fp == NULL)
	{
		printf("Error opening file");
		return (-1);
	}
	
	while(getline(&b, &bufsize, fp) != -1)
	{           
		printf("%s", b);

		char *c = strtok(b, " ");
		printf("%s ", c);
		while( c != NULL)
		{
			root = addtree(root, c);
			c = strtok(NULL, " ");
			printf("%s ", c);
		}
		
	}


	
	treeprint(root);

	fclose(fp);
	return 0;
}