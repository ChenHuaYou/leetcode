#include "leetcode.h"

int main(){
	Solution s;
    string haystack = "mississippi";
    string needle = "issip";
    int index = s.strStr(haystack, needle);
    printf("index is : %d\n",index);
}
