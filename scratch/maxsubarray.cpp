#include <iostream>
#include <vector>
using namespace std;



#define MAX(a, b) ((a)>(b)?(a):(b))

class SolutionArray {
public:
	int maxSubArray(int* nums, int numsSize)
	{
	    int i;
	    int best = INT_MIN;
	    int currsum = 0;
	    for (i = 0; i < numsSize; i++) {
	        currsum = MAX(currsum + nums[i], nums[i]);
	        best = MAX(best, currsum);
	    }
	    return best;
	}
};


int main(){

	int nums[9] = {-2,1,-3,4,-1,2,1,-5,4};
	SolutionArray x;
	int y = x.maxSubArray(nums, 9);
	cout << "max subarray of array y is " << y << "\n";


  return 0;
}