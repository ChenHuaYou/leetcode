#include "leetcode.h"

int main(){
	Solution s;
    string haystack = "ABC ABCDAB ABCDABCDABDE";
    string needle = "ABCDABD";
    int p = s.strStr(haystack, needle);
    printf("index: %d",p);
}
