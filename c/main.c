#include "leetcode.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(){
    int nums0[] = {1,4,5,1,3,4,2,6};
    heapSort(nums0, 8);
    int i=0;
    while(i<8){
        printf("%d ",nums0[i++]);
    }
    printf("\n");
}
