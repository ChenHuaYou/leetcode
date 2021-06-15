#include "leetcode.h"
#include <stdlib.h>
#include <stdio.h>

int main(){
    int height[] = {1,8,6,2,5,4,8,3,7};
    int heightSize = sizeof(height)/sizeof(int);
    int area = maxArea(height, heightSize);
    printf("%d\n",area);

}
