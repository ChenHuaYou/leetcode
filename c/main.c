#include "leetcode.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main(){
    int nums[] = {1,1,1,2,2,2,3,3};
    printIntVec(nums,8);
    int length = removeDuplicates(nums, 8);
    printIntVec(nums,length);
}
