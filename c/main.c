#include "leetcode.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main(){

    char *haystack = "ABC ABCDAB ABCDABCDABDE";
    char *needle = "ABCDABD";
    int index = strStr(haystack, needle);
    printf("index is : %d",index);
}
