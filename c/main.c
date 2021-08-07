#include "leetcode.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(){
    int returnSize;
    char **s = generateParenthesis(8, &returnSize);
    for(int i=0; i<returnSize; i++){
        printf("%s\n",s[i]);
        free(s[i]);
    }
    free(s);
}
