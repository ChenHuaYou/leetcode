#include <stdbool.h>
#include "uthash.h"

struct ListNode* createListNodes(int* nums, int numSize);
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
struct HashMap{
    int key;
    int val;
    UT_hash_handle hh;
};
bool isValid(char * s);
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2);
char ** generateParenthesis(int n, int* returnSize);
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize);

void heapSort(int *arr, int size);
