#include "bst.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tnode *addtree(struct tnode *p, char *word)
{
	if (p == NULL)
	{
		p = (struct tnode *)malloc(sizeof(struct tnode));
		p->word = strdup(word);
		p->count = 1;
		p->left = NULL;
		p->right = NULL;
	}
	
	else if (strcmp(p->word, word) == 0)
	{
		p->count++;
	}

	else if (strcmp(p->word, word) < 0) //add word left child
	{
		p->left = addtree(p->left, word);
	}
	
	else if (strcmp(p->word, word) > 0)
	{
		p->right = addtree(p->right, word);
	}
	
	return p;
}

void treeprint(struct tnode *p){
	if(p != NULL)
	{
		treeprint(p->left);
		printf("%s: %d\n", p->word, p->count);
		treeprint(p->right);
	}
}