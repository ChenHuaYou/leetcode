#include "leetcode.h"
#include <stdlib.h>
#include <stdio.h>

int main(){

    char *inputs[] = {
        /*"aa",
        "aa",
        "ab",
        "mississippi",*/
        "abcdefghijklmn",
    };

    char *pattern[] = {
        /*"a",
        "a*",
        ".*",
        "mis*is*p*.",*/
        "a*a*a*a*a*a*a*a*a*a*c",
    };

    int n = sizeof(inputs)/sizeof(inputs[0]);
    for(int i=0; i<n; i++){
        printf("%s : %s\n",inputs[i],pattern[i]);
       printf("%d\n",isMatch(inputs[i],pattern[i]));
    }
}
