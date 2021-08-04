#include "leetcode.h"
#include <stdlib.h>
#include <stdio.h>

int main(){
    int nums[5] = {2,2,2,2,2};
    int returnSize=0;
    int *returnColumnSizes=NULL;
    int** res = fourSum(nums, 5, 8, &returnSize, &returnColumnSizes);
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
