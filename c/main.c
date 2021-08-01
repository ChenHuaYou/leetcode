#include "leetcode.h"
#include <stdlib.h>
#include <stdio.h>

int main(){
    int nums[] = {-1,0,1,2,-1,-4};
    int *returnSize = calloc(1,sizeof(int));
    int **returnColumnSizes = calloc(*returnSize,sizeof(int *));
    int **res = threeSum(nums, 6, returnSize, returnColumnSizes);

    for(int i=0; i < *returnSize; i++){
        for(int j=0; j<3; j++){
            printf("%d ",res[i][j]);
        }
        printf("\n");
    }
    free(returnSize);
    free(returnColumnSizes);
}
