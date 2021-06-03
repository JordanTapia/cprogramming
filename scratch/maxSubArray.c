#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

int maxSubArray(int* nums, int numsSize){
    int curSum = nums[0];
    int maxSum = curSum;
    for(int i = 1; i < numsSize; i++){
    	curSum = curSum + nums[i];
    	printf("nums[%d] = %d - curSum: %d, maxSum: %d\n", i, nums[i], curSum, maxSum);

        
        
        if (nums[i] > maxSum) {
            maxSum = nums[i];
            curSum = maxSum;
        }
        else if(curSum > maxSum) {
            maxSum = curSum;
        }
    }
    return maxSum;
}

int main() {

	int nums[9] = {-2,1,-3,4,-1,2,1,-5,4 };

	printf("max subarray of nums is: %d\n", maxSubArray(nums, 9));

	return 0;
}