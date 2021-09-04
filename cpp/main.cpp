#include "leetcode.h"

int main(){
	Solution s;
    vector<int> nums = {1,1,1,2,2,2,3,3};
    s.removeDuplicates(nums);
    printIntVec(nums);
}
