#include "leetcode.h"
#include <stdlib.h>
#include <stdio.h>

int main(){
    int nums[] = {3,4,9,58,1994};
    for(int i=0;i<5;i++){
        char * s = intToRoman(nums[i]);
        printf("%s\n",s);
    }

}
