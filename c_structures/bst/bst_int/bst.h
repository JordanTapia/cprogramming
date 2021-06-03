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
struct TreeNode *addtree(struct TreeNode *p, int val);

// Print BST sorted ascending.
void printSorted(struct TreeNode *p);

// Helper to isValidBST. Add BST to int array.
void addToArray(struct TreeNode *p, int *nums, int *numsIndex);

// Check for valid BST.
// Returns true if addToArray returns a sorted ascending array.
bool isValidBST(struct TreeNode* root);

// Delete node with key from BST
struct TreeNode* deleteNode(struct TreeNode* root, int key);

#endif