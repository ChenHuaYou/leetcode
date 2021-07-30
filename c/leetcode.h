#include <stdbool.h>

int myAtoi(char * s);
bool isPalindrome(int x);
bool isMatch(char * s, char * p);

typedef struct{
    int num_nodes;
    char *graph;
    int status;
} pattern;

pattern * pattern_compile(char * p);
char * ReversePolishNotation(char * s);

/*
 * 从数组 a1,...,an 寻找子数组 ai,a(i+1),...,a(j)使得 (j-i)*min(ai,aj)最大
 * 1*min(a1,a2),2*min(a1,a3),...,(n-2)*min(a1,a(n-1)),(n-1)*min(a1,an)
 * 1*min(a2,a3),2*min(a2,a4),...,(n-2)*min(a2,a(n-1))
 */
int maxArea(int* height, int heightSize);

// 12. 整数转罗马数字
char * intToRoman(int num);
