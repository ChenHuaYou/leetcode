#include "leetcode.h"

int main(){
	Solution s;
    string haystack = "hello";
    string needle = "ll";
    int index = s.strStr(haystack, needle);
    printf("index is : %d\n",index);
}
