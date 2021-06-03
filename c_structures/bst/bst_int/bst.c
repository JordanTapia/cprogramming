#include "bst.h"

struct TreeNode *addtree(struct TreeNode *p, int val)
{
	if (p == NULL)
	{
		p = (struct TreeNode *)malloc(sizeof(struct TreeNode));
		p->val = val;
		p->left = NULL;
		p->right = NULL;
	}
	else if (val < p->val)
	{
		p->left = addtree(p->left, val);
	}
	else if (val > p->val)
	{
		p->right = addtree(p->right, val);
	}
	return p;
}

void printSorted(struct TreeNode *p){
	if(p != NULL)
	{
		printSorted(p->left);
		printf("%d ", p->val);
		printSorted(p->right);
	}
}

void addToArray(struct TreeNode *p, int *nums, int *numsIndex){	
	if(p != NULL)
	{
		addToArray(p->left, nums, numsIndex);
		nums[*numsIndex] = p->val;
		(*numsIndex)++;
		addToArray(p->right, nums, numsIndex);
	}
	return;
}


bool isValidBST(struct TreeNode* root){
    if(root == NULL) {
    	return true;
    }
    int numsSize = MAX_BST_SIZE;
    int nums[numsSize];
    int numsIndex = 0;
    int *numsIndexPtr = &numsIndex;
    addToArray(root, nums, numsIndexPtr);
    for(int i = 0; i < *numsIndexPtr - 1; i++) {
    	if(nums[i] > nums[i + 1]) {
    		return false;
    	}
    }
    return true;
}

/* 
	deleteNode has 3 cases to delete:
	1. Node is leaf - delete leaf
	2. Node has one child - delete node, move root->left or root->right
	3. Node has wo children - use inorder successor and swap with successor
*/
struct TreeNode* deleteNode(struct TreeNode* root, int key){
	if(root == NULL) {
		return root;
	}
	/* Traverse to Node with key */
	else if(root->val < key) {
		root->right = deleteNode(root->right, key);
		return root;
	}
	else if(root->val > key) {
		root->left = deleteNode(root->left, key);
		return root;
	}
	/* Case 1 */
	if(root->left == NULL && root->right == NULL) {
		printf("deleting leaf\n");//
		free(root);
		return NULL;
	}
	/* Case 2 */
	else if(root->left == NULL && root->right) { // case2a
		struct TreeNode* rightChild = root->right;
		free(root);
		return rightChild;
	}
	else if(root->right == NULL && root->left) { // case 2b
		struct TreeNode* leftChild = root->left;
		free(root);
		return leftChild;
	}
	/* Case 3 */
	else {
		struct TreeNode* successorParent = root;
		struct TreeNode* successor = root->right;
		/*
			Successor is the next adjacent value greater than key.
			It is either the nearest right node with no left children,
			or the farthest left node of the nearest right node. 
		*/
		if(successor->left == NULL) {
			root->val = successor->val;
			successorParent->right = successor->right;
		}
		else {
				while(successor->left != NULL) {
				successorParent = successor;
				successor = successor->left;
			}	
			root->val = successor->val;
			successorParent->left = successor->right;
		}
		free(successor);
		return root;
	}
}








