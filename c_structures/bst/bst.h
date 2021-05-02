#ifndef __BST_H__
#define __BST_H__


#define MAXSIZE  7

struct tnode {
	char *word;
	int count;
	struct tnode *left;
	struct tnode *right;
};

struct tnode *addtree(struct tnode *p, char *word);

void treeprint(struct tnode *p);


#endif