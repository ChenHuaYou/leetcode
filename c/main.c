#include "leetcode.h"
#include <stdlib.h>
#include <stdio.h>

int main(){
    int nums[10] ={-4,-3,-2,-1,0,0,1,2,3,4};
    int target = 0;
    int returnSize=0;
    int *returnColumnSizes=NULL;
    int** res = fourSum(nums, 10, target, &returnSize, &returnColumnSizes);
    for(int i=0; i<returnSize; i++){
        for(int j=0; j<returnColumnSizes[i]; j++){
            printf("%d ",res[i][j]);
        }
        printf("\n");
        free(res[i]);
    }
    free(res);
    free(returnColumnSizes);
}
