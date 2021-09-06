#include "leetcode.h"

int main(){
	Solution s;
    vector<int> nums = {1,1,1,2,2,2,3,3};
    s.removeElement(nums,1);
    printIntVec(nums);
}
