#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int rize = 2 * sizeof(int);
    int *returnSizeArray = (int *)malloc(rize);   
    for(int i = 0; i < numsSize; i++) {        
        for(int j = i + 1; j < numsSize; j++) {           
            if(nums[i] + nums[j] == target) {
                returnSizeArray[0] = i;
                returnSizeArray[1] = j;
                return returnSizeArray;
            }
        }
    } return returnSizeArray;
}


int main() {

    int nums[4] = {2, 7, 11, 15};
    int a = 2;
    int *returnSize = &a;
    int *x = twoSum(nums, 4, 9, returnSize);
    printf("%d %d\n", x[0], x[1]);
}