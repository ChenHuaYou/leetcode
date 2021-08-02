#include "leetcode.h"
#include <stdlib.h>
#include <stdio.h>

int main(){
    int nums[] = {-1,2,1,-4};
    int target = 1;
    int res = threeSumClosest(nums, 4, target);
    printf("%d \n",res);
}
