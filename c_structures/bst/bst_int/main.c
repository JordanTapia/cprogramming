
/*

	Jordan Tapia
	05-02-2021
	
	@Target
		This implements a BST to sort and count ints from array in main. 
	@main.c
		This uses a binary search tree to sort a hard-coded array of ints
	@bst.c
		The bst implementation

	To do:
		Modify the addArray function to allocate memory dynamically.

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "bst.h"

#define NUMSSIZE 6 //size of hard-coded array for testing in main
#define NUMSARRAY { 50, 30, 70, 40, 60, 80}
int main(){

	
	struct TreeNode *root;
	root = NULL;
	int nums[NUMSSIZE] = NUMSARRAY;
	for (int i = 0; i < NUMSSIZE; i++)
	{
		root = addtree(root, nums[i]);
	}
	printSorted(root);
	printf("\n");

	root = deleteNode(root, 50);

	printSorted(root);
	printf("\n");

	return 0;
}