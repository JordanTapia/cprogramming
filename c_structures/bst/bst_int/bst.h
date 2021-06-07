#ifndef __BST_H__
#define __BST_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_BST_SIZE 10000

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

// Add node to BST. 
// Does nothing for repeat values.
// Returns head of BST
struct TreeNode *addtree(struct TreeNode *p, int val);

// A DANGEROUS helper to isValidBST. Add BST to int array.
void addToArray(struct TreeNode *p, int *nums, int *numsIndex);

// A 'SAFE' way alternative to addToArray for adding BST to int array.
// It allocates 10,000 int array by default.
// Might want to change to dynamically allocated memory.
void arrayify(struct TreeNode *root, int * nums, int *size);

// DANGEROUSLY checks for valid BST.
// Returns true if addToArray returns a sorted ascending array.
bool isValidBST(struct TreeNode* root);

// Delete node with key from BST
// Returns head of BST.
struct TreeNode* deleteNode(struct TreeNode* root, int key);

// Returns the minimum distance between sorted elements of a BST
int getMinimumDifference(struct TreeNode* root);

// return BST depth
int maxDepth(struct TreeNode* root);

// Returns level order array of **int levelOrder
// this contains some nasty pointer arithmetic.
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes);

// Example code someone osted on leetcode discussion. not mine. 
int** levelOrder2(struct TreeNode* root, int** columnSizes, int* returnSize);

// Print BST sorted ascending.
void printSortedBST(struct TreeNode *p);

// Print array
void printArray(int *nums, int size);

// Print a BST using level-sorted array
void printLevelArray(int **nums, int *returnSize, int **returnColumnSizes);

#endif