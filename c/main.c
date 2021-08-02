#include "leetcode.h"
#include <stdlib.h>
#include <stdio.h>

int main(){
    int nums[] = {-7,-4,-6,6,4,-6,-9,-10,-7,5,3,-1,-5,8,-1,-2,-8,-1,5,-3,-5,4,2,-5,-4,4,7};
    int returnSize;
    int *returnColumnSizes;
    int **res = threeSum(nums, 27, &returnSize, &returnColumnSizes);

    for(int i=0; i < returnSize; i++){
        for(int j=0; j<3; j++){
            printf("%d ",res[i][j]);
        }
        printf("\n");
    }
    for(int i=0; i<returnSize; i++){
        free(res[i]);
    }
    free(res);
    free(returnColumnSizes);
}
