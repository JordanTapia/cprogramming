
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
		fix array of returnColumnSizes so that levelOrder function can return modified array
		compile time switches for different tests in main
		Modify the addArray function to allocate memory dynamically. it is dangerous
		isValid BST is also dangerous...it calls addtoarray
		clean up arrayify()
		clean up getMinDistance()

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "bst.h"

#define NUMSSIZE 15 //size of hard-coded array for testing in main
#define NUMSARRAY { 2, 1, 7, 5, 8, 6, 9, 0, 14, 66, 65, 52, 18, 44, 32}
int main(){

	

	int nums[NUMSSIZE] = NUMSARRAY;
	printArray(nums, NUMSSIZE);

	struct TreeNode *root;
	root = NULL;
	for (int i = 0; i < NUMSSIZE; i++)
	{
		root = addtree(root, nums[i]);
	}
	printSortedBST(root);

	

	/* // TEST CODE
	int min = getMinimumDifference(root);
	printf("min: %d\n", min);
	/*/

	/* // TEST CODE
	int depth = maxDepth(root);
	printf("depth: %d\n", depth);
	*/

	/* // TEST CODE
	if(isValidBST(root)) {
		printf("valid BST\n");
	} else {
		printf("INVALID BST\n");
	}
	*/
	int rs = 0;
	int* returnSize = &rs;
	int** returnColumnSizes;

	//printf("rCS: %d\n", returnColumnSizes);
	int** levelArray = levelOrder2(root, returnSize, returnColumnSizes);
	//printf("rSize: %d\n", *returnSize);
	//printf("rCS: %d\n", returnColumnSizes);

	printLevelArray(levelArray, returnSize, returnColumnSizes);
	/*
	for(int i = 0; i < returnSize; i++) {
		for(int j = 0; j < *(returnColumnSizes + i); j++) {
			printf("%d ", *(levelArray[i] + j));
		}
	}
	*/
	return 0;
}











