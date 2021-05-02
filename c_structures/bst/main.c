
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "bst.h"
#include "parser.h"
/*

	Jordan Tapia
	05-02-2021
	
	@Target
		This implements a BST to sort and count words from 
		input.txt or hardcoded array. Commented out code was an attempt
		to read from a file...need to figure this out someday.
	@main.c
		This uses a binary search tree to sort a hard-coded array of colors
	@bst.h
		The bst implementation
	@parser.h
		Parser that doesn't work	

	The BST is useable elsewhere. I've tried in main to do file input. It works but 
	will always have weird spaces and nulls everywhere. Can't quite figure it out.
	One workaround would be column input only.

*/

int main(){

	
	char *list[MAXSIZE] = {
	"red",
	"orange",
	"yellow",
	"green",
	"orange",
	"indigo",
	"violet"
	};
	
	struct tnode *root;
	root = NULL;

	for (int i = 0; i < 7; i++)
	{
		root = addtree(root, list[i]);
	}


	treeprint(root);

	/* char *fgets(char *str, int n, FILE *stream) */


	/*

	char * line;
	size_t bufsize = 100;														
	FILE *fp = fopen("input.txt", "r");

	if(fp == NULL)
	{
		printf("Error opening file");
		return (-1);
	}
	
	while(getline(&line, &bufsize, fp) != -1)
	{           
		//printf("%s", b);
		char *word = strtok(line, " ");
		//word = my_strtrimlead(word);
		//printf("%s ", word);
		//printf("len: %d", strlen(c));


		while( word != NULL)
		{
			
			
			root = addtree(root, word);
			word = strtok(NULL, " ");

			
			printf("%s ", word);
			word = my_strtrimlead(word);
			//printf("len: %d", strlen(c));
		}
		
	}
	fclose(fp);
	*/

	
	return 0;
}