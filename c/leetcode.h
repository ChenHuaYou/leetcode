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
int maxArea(int* height, int heightSize);
char * intToRoman(int num);
int romanToInt(char * s);
char * longestCommonPrefix(char ** strs, int strsSize);
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes);
int threeSumClosest(int* nums, int numsSize, int target);
int cmpfunc (const void * a, const void * b);
char ** letterCombinations(char * digits, int* returnSize);
int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes);
struct ListNode {
    int val;
    struct ListNode *next;
};
struct ListNode* removeNthFromEnd(struct ListNode* head, int n);
