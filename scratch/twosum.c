#include <stdlib.h>
#include <stdio.h>

#define NUMSIZE 3

int* twoSum(int* nums, int numsSize, int target, int *returnSize){

    
	//*returnSize = 2;
    //printf("size of returnSize: %d\n", sizeof(int)*2);
    
    for(int i = 0; i < numsSize; i++)
    {
        for(int j = i+1; j < numsSize; j++)
        {
            
            if( (nums[i] + nums[j] == target) && (j != i) )
            {
            	//printf("%d %d\n", i, j);
            	int *indices = (int *)malloc(sizeof(int) * 2);
                indices[0] = (i < j ? i : j);
                indices[1] = (i > j ? i : j);
                return indices;

            }            
        }
    }
    return NULL;
    
    
}



int main(){
	
	//int numsize = 5;
	//int nums[numsize];
	int nums[NUMSIZE] = {3, 2, 4};
	int target = 6;

	int *index = NULL;
	index = twoSum(nums, NUMSIZE, target, index);
	printf("%d %d\n", index[0], index[1]);
}