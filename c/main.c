#include "leetcode.h"
#include <stdlib.h>
#include <stdio.h>

int main(){

    char *inputs[] = {"42","   -42","4193 with words","words and 987","-91283472332"};
    int n = sizeof(inputs);
    for(int i=0; i<n; i++){
       printf("%d\n",myAtoi(inputs[i]));
    }
}
