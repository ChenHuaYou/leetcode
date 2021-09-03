#include <stdbool.h>
#include <stdio.h>
#include "uthash.h"
#include <stdarg.h>


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
struct ListNode* mergeKListsByHeapSort(struct ListNode** lists, int listsSize);

static inline struct ListNode* createNodes(int size,...){
    va_list valist;
    va_start(valist, size);

    struct ListNode* head = malloc(sizeof(struct ListNode));
    head->val = va_arg(valist,int);
    head->next = NULL;
    struct ListNode* curr =  head;
    for(int i=1;i<size;i++){
        curr->next = malloc(sizeof(struct ListNode));
        curr=curr->next;
        curr->val=va_arg(valist,int);
        curr->next=NULL;
    }
    return head;
}

static inline void freeNodes(struct ListNode* head){
    while(head!=NULL) {
        struct ListNode* tmp = head;  
        head = head->next; 
        free(tmp); 
    }
}

static inline void printNodes(struct ListNode* head){
    while(head != NULL){
        printf("%d ",head->val);
        head = head->next;
    }
    printf("\n");
}


struct ListNode* swapPairs(struct ListNode* head);


struct my_struct {
    int id;                    /* key */
    char name[10];
    UT_hash_handle hh;         /* makes this structure hashable */
};
