#include "leetcode.h"
#include <stdlib.h>
#include <stdio.h>

int main(){

    int inputs[] = {
        121,
        -121,
        -10,
        -101,
    };
    int n = sizeof(inputs)/sizeof(inputs[0]);
    for(int i=0; i<n; i++){
       printf("%d\n",isPalindrome(inputs[i]));
    }
}
