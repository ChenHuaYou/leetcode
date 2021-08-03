#include "leetcode.h"
#include <stdlib.h>
#include <stdio.h>

int main(){
    char *digits = "2345627";
    int returnSize=0;
    char** res = letterCombinations(digits, &returnSize);
    for(int i=0; i<returnSize; i++){
        printf("%s\n",res[i]);
        free(res[i]);
    }
    free(res);
}
