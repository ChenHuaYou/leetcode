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
typedef struct ListNode ListNode;
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

/**
 * 给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。
 * k是一个正整数，它的值小于或等于链表的长度。
 * 如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序
 **/
struct ListNode* reverseKGroup(struct ListNode* head, int k);
/**
 *给你一个有序数组 nums ，请你 原地 删除重复出现的元素，使每个元素 只出现一次 ，返回删除后数组的新长度。
 *不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。
 **/
int removeDuplicates(int* nums, int numsSize);
int erase(int nums[], int start, int end, int length);
void printIntVec(int *nums, int length);
/**
  给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。
  不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并 原地 修改输入数组。
  元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素
 **/
int removeElement(int* nums, int numsSize, int val);
