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

void printSortedBST_helper(struct TreeNode *p){
	if(p != NULL)
	{
		printSortedBST_helper(p->left);
		printf("%d\n", p->val);
		printSortedBST_helper(p->right);
	}
}

void printSortedBST(struct TreeNode *p) {
	printf("\n Printing BST sorted:\n");
	printSortedBST_helper(p);
	printf("\n");
}

void printArray(int *nums, int size) {
	printf("\n Printing array:\n");
	for(int i = 0; i < size; i ++) {
		printf("%d: %d\n", i, *(nums + i));
	}
	printf("\n");
}



void printLevelArray(int **nums, int *returnSize, int **returnColumnSizes) {
	printf("\n Printing Level array:\n");
	for(int i = 0; i < *returnSize; i++) {


		//printf("in first forloop \n");
		//printf("rSize: %d\n", *returnSize);
		//printf("returnColumnSizes: %d\n", **(returnColumnSizes));

		printf("\n[");
		for(int j = 0; j < **(returnColumnSizes + i); j++){


			//print index
			printf(" (%d, %d) = ", i, j);

			if(j == *(*returnColumnSizes + i) - 1) {
				printf("%d", *(*(nums + i) + j));
			}
			else {
				printf("%d, ", *(*(nums + i) + j));
			}
		}
		if(i == *returnSize - 1) {
			printf("]\n");
		} else {
			printf("]");
		}
	}
	printf("\n");
}


//convert BST to sorted array nums
//return size of sorted array nums
//use recursive call left-side
//arrayify is a weird name. toArray(root) might be better
void arrayify(struct TreeNode *root, int * nums, int *size) {
	if(root == NULL) {
		return;
	}
	arrayify(root->left, nums, size);
	nums[(*size)++] = root->val;
	arrayify(root-> right,nums, size);
	return;
}

/*
//dangerous, need to either delete or fix
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

//dangerous, need to either delete this or fix it
*/

bool isValidBST(struct TreeNode* root){
    if(root == NULL) {
    	return true;
    }
    int nums[MAX_BST_SIZE];
    int numsSize = 0;
    arrayify(root, nums, &numsSize);
    for(int i = 0; i < numsSize - 1; i++) {
    	if(nums[i] >= nums[i + 1]) {
    		return false;
    	}
    }
    return true;
}

/* 
	DeleteNode removes node with key. DeleteNode has 3 cases to delete:
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



//min function should be cleaned up, it's repetitive and hard to read
int getMinimumDifference(struct TreeNode* root){
	int nums[MAX_BST_SIZE];
	int size = 0;
	arrayify(root, nums, &size);
	//printArray(nums, size);///////
	//minm diff is between adjacent nodes when sorted
	//return min of diff between adjacent values in array
	int min = nums[0] - nums[1];
	if(min < 0) {min *= -1;}
	int curVal;
	for(int i = 1; i < size - 1; i ++) {
		curVal = nums[i] - nums[i + 1];
		if(curVal < 0) {
			curVal *= -1;
		}
		if(curVal < min) {
			min = curVal;
		}
	}
	return min;
}


int maxDepth(struct TreeNode* root){
	if(root == NULL) {
		return 0;
	}
	int depthL = 1 + maxDepth(root->left);
	int depthR = 1 + maxDepth(root->right);
	return (depthL > depthR ? depthL : depthR);
}


void levelOrderHelper(struct TreeNode* root, int **bstArray, int **returnColumnSizes, int *depth) {
	if(root == NULL) {
		return;
	}
	(*depth)++;

	levelOrderHelper(root->left, bstArray, returnColumnSizes, depth);
	int i = *depth - 1;
	
	//*((*bstArray + i) + *(returnColumnSizes + i)) = root->val;
	//printf("hdepth: %d\n", *depth);
	*(*(bstArray + i) + **(returnColumnSizes + i)) = root->val;
	//printf("i: %d\n", i);


	//print bstArray value
	printf("bstArray[%d][%d]: %d, root->val: %d, depth: %d\n", i, *(*returnColumnSizes + i), 
		*(*(bstArray + i) + **(returnColumnSizes + i)), root->val, *depth);

	**(returnColumnSizes + i) += 1;

	//printf("rCS[%d]: %d\n", i, **(returnColumnSizes + i) );

	levelOrderHelper(root->right, bstArray, returnColumnSizes, depth);
	(*depth)--;
	return;
}

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
	// get dimensions required for BST to 2x2 array
	int depth = maxDepth(root);
	*returnSize = depth;
	int nodeLength = 1;
	for(int i = 0; i < depth - 1; i++) {
		nodeLength += 2;
	}



	// allocate space for array that will contain level order traversal of BST
	int **bstArray = malloc(sizeof(int *) * depth);
	for(int i = 0; i < depth; i++) {
		*(bstArray + i) = malloc(sizeof(int *) * nodeLength); //bst array implicitly made a ptr to ptr **?
		//printf("*(bstArray + i): %x, **(bstArray + i): %d\n", *(bstArray + i), *(*(bstArray + i)));
	}
	// allocate space for array of column sizes. init to 1.
	//printf("depth:%d, sizeof(int ): %d\n", depth, sizeof(int));
	returnColumnSizes = malloc(sizeof(int *) * depth);

	//printf("rCS: %x\n", returnColumnSizes);
	//printf("malloc space for returnColumnSizes\n");
	//printf("size of returnColumnSizes: %d\n", sizeof(*returnColumnSizes));

	//malloc'd int*...need to malloc int also?
	for(int j = 0; j < depth; j++) {
		*(returnColumnSizes + j) = malloc(sizeof(int));
		**(returnColumnSizes + j) = 0;
		//printf("**(returnColumnSizes + %d): %x\n", j, **(returnColumnSizes + j));
	}

	int startTravDepth = 0;
	//printf("calling helper, malloc3'd OK\n");
	levelOrderHelper(root, bstArray, returnColumnSizes, &startTravDepth);

	//printf("rCS: %\n", returnColumnSizes);

	return bstArray;
}



///////Example Code someone posted on LeetCode discussion////////
int** levelOrder2(struct TreeNode* root, int** columnSizes, int* returnSize) {
	int **result = NULL;
	if (root == NULL) {
	    *columnSizes = NULL;
	    *returnSize = 0;
	    return NULL;
	}

	*columnSizes = NULL;
	*returnSize = 0;

	struct TreeNode **queue = (struct TreeNode **)malloc(sizeof(struct TreeNode *));
	struct TreeNode *pop;
	int start = 0, end = 0, length = 0;
	queue[end++] = root;
	length = 1;

	while (length > 0) {
	    result = (int **)realloc(result, (*returnSize+1)*sizeof(int *));
	    result[*returnSize] = (int *)malloc(sizeof(int)*length);
	    *columnSizes = (int *)realloc(*columnSizes, (*returnSize+1)*sizeof(int));
	    (*columnSizes)[*returnSize] = length;

	    for (int i=0; i<length; i++) {
	        pop = queue[start++];
	        result[*returnSize][i] = pop->val;
	        if (pop->left) {
	            queue = (struct TreeNode **)realloc(queue, sizeof(struct TreeNode *)*(end+1));
	            queue[end++] = pop->left;
	        }
	        if (pop->right) {
	            queue = (struct TreeNode **)realloc(queue, sizeof(struct TreeNode *)*(end+1));
	            queue[end++] = pop->right;
	        }
	    }
	    length = end-start;
	    *returnSize += 1;
	}

	return result;
}











