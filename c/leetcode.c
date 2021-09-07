#include "uthash.h"
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "leetcode.h"
#include "stdio.h"


struct ListNode* swapPairs(struct ListNode* head){
    struct ListNode *prev, *curr, *next;
    prev = NULL;
    curr = head;
    next = NULL;
    while(curr != NULL){
        next = curr->next;
        if(next==NULL) break;
        curr->next = next->next;
        next->next = curr;
        if (prev==NULL){ 
            head = prev = next;
        }else{
            prev->next = next;
        }
        prev = next->next;
        curr = curr->next;
    }
    return head;
}

//build max heap
//the heap assume that child heap is max-heap
void nodeSwap(struct ListNode** a, struct ListNode** b){
    struct ListNode* tmp = *a;
    *a = *b;
    *b = tmp;
}
void nodeHeapify(struct ListNode** arr, int start, int size){
    int parent = start;
    int child = parent*2+1;
    while(child<size){
        if(child+1 < size && arr[child]->val < arr[child+1]->val){
            child ++;
        }
        if(arr[parent]->val>arr[child]->val){
            return;
        }else{
            nodeSwap(arr+parent,arr+child);
            parent = child;
            child = parent * 2 + 1;
        }
    }
}
void initHeap(struct ListNode** arr, int size){
    for(int i=(size-1)/2; i>=0; i--){
       nodeHeapify(arr, i, size); 
    }
}
void nodeHeapSort(struct ListNode** arr, int size){
    initHeap(arr, size);
    while(size>1){
        nodeSwap(arr,arr+size-1);
        nodeHeapify(arr, 0, --size);
    }
}

struct ListNode* mergeKListsByHeapSort(struct ListNode** lists, int listsSize){
    if(listsSize==0) return NULL;
    struct ListNode* head=NULL;
    int maxSize = 3*listsSize;
    struct ListNode** arr = calloc(maxSize, sizeof(struct ListNode*));
    int k=0;
    for(int i=0; i<listsSize; i++){
        while(lists[i]!=NULL){
           arr[k++] = lists[i]; 
           if (k==maxSize-1) {
               maxSize *= 2;
               arr=realloc(arr, maxSize*sizeof(struct ListNode*));
           }
           lists[i] = lists[i]->next;
        }
    }
    if(k==0) return NULL;
    nodeHeapSort(arr, k);
    for(int i=0; i<k; i++){
        arr[i]->next = arr[i+1];
    }
    arr[k-1]->next = NULL;
    head = arr[0];
    free(arr);
    return head;
}

//输入：lists = [[1,4,5],[1,3,4],[2,6]]
//输出：[1,1,2,3,4,4,5,6]
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    struct ListNode* head=NULL;
    struct ListNode* current=NULL;
    struct ListNode* next=NULL;
    int pos = 0;

    while(true){
        int nullCount = 0;
        for(int i=0; i<listsSize; i++){
            if(lists[i]==NULL) {
                nullCount++;
                continue;
            }else if(next==NULL){
                next = lists[i];
                pos = i;
                continue;
            }
            //printf("%d %p %p \n",i, next, lists[i]);
            if(next->val > lists[i]->val){
                next = lists[i];
                pos = i;
            } 
        }
        if(nullCount==listsSize) break;
        //printf("choose %d\n",pos);
        lists[pos] = lists[pos]->next;
        if(head==NULL) {
            current = head = next;
        }else{
            current->next = next;
            current = next;
        }
        next = NULL;
    }
    return head;
}

//数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

struct parenteses{
    char* stack;
    int* push;
    char* path;
    int maxDepth;
    char** res;
    int* returnSize;
    int maxRetSize;
};

void backtrace_parentheses(struct parenteses* p){
    if(strlen(p->path) == p->maxDepth){
        if(strlen(p->stack)==0){
            p->res[*p->returnSize] = calloc(p->maxDepth+1, sizeof(char));
            strcpy(p->res[*p->returnSize], p->path);
            (*p->returnSize)++;
            if(*p->returnSize==p->maxRetSize){
                p->maxRetSize += 5;
                p->res = realloc(p->res,p->maxRetSize * sizeof(char *)); 
            }
        }
    }else{
        //left '(' and right ')
        //we go left and then right
        p->path[strlen(p->path)] = '(';
        p->stack[strlen(p->stack)]='(';
        *(++p->push)= 1;
        backtrace_parentheses(p);

        if (strlen(p->path)==0) return;
        p->path[strlen(p->path)] = ')';
        if(strlen(p->stack)==0){
            p->stack[strlen(p->stack)]=')';
            *(++p->push)= 1;
        }else if(p->stack[strlen(p->stack)-1] == '('){
                p->stack[strlen(p->stack)-1]='\0';
                *(++p->push) = -1;
        }else{
                p->stack[strlen(p->stack)]=')';
                *(++p->push)= 1;
        }
        backtrace_parentheses(p);
    }
    //path and stack roll back to parent status
    p->path[strlen(p->path)-1] = '\0';
    if(*p->push==1){//if push
        p->stack[strlen(p->stack)-1] = '\0';
        p->push --;
    }else if(*p->push==-1){//if pop
        p->stack[strlen(p->stack)] = '(';
        p->push --;
    }
}
char ** generateParenthesis(int n, int* returnSize){
    struct parenteses pt;
    *returnSize = 0;
    pt.maxRetSize = 5;
    pt.returnSize = returnSize;
    pt.maxDepth = 2*n;
    pt.path = calloc(2*n+1, sizeof(char));
    pt.stack = calloc(2*n+1,sizeof(char));
    pt.res = calloc(5, sizeof(char *));
    pt.push = calloc(2*n+1,sizeof(int));
    backtrace_parentheses(&pt);
    free(pt.path);
    free(pt.stack);
    free(pt.push);
    return pt.res;
}



//将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *head=NULL, *tail=NULL;
    if(l1->val>l2->val){
        tail=head=l2;
        l2=l2->next;
    }else{
        tail=head=l1;
        l1=l1->next;
    }

    while(l1!=NULL || l2!= NULL){
        if(l1==NULL) {
            tail->next = l2;
            l2 = l2->next;
            continue;
        }
        if(l2==NULL) {
            tail->next = l1;
            l1 = l1->next;
            continue;
        }
        if(l1->val>l2->val){
            tail->next = l2;
            l2=l2->next;
        }else{
            tail->next = l1;
            l1=l1->next;
        }
    }
    return head;
}

int map(char ch){
    int out = 0;
    switch (ch) {
        case '(': out = 1; break ;
        case ')': out = -1; break ;
        case '{': out = 2; break ;
        case '}': out = -2; break ;
        case '[': out = 3; break ;
        case ']': out = -3; break ;
    }
    return out;
}

//给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效
bool isValid(char * s){
    if(strlen(s)==0) return true;
    char *base = calloc(strlen(s),sizeof(char));
    int top = -1;
    for(int i=0; i<strlen(s); i++){
        if(top==-1){
            base[++top] = s[i];
            continue;
        }
        if(map(s[i])+map(base[top])==0 && map(base[top])>0){
            top--;
        }else{
            base[++top]=s[i];
        }
    }
    free(base);
    if(top==-1){
       return true; 
    }

    return false;
}


//给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。

struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode *p = head;
    int count = 0;
    int maxSize = 5;
    struct ListNode **record = calloc(maxSize, sizeof(struct ListNode *));
    while (p != NULL){
        record[count++] = p;
        if(count==maxSize) {
            maxSize += 5;
            record = realloc(record, maxSize * sizeof(struct ListNode *));
        }
        p = p->next;
    }
    if(count-n-1>=0){
        record[count-n-1]->next = record[count-n]->next;
    }else{
        head = record[count-n]->next;
    }
    free(record[count-n]);
    free(record);
    return head;
}

//给定一个包含 n 个整数的数组 nums 和一个目标值 target，
//判断 nums 中是否存在四个元素 a，b，c 和 d ，
//使得 a + b + c + d 的值与 target 相等？找出所有满足条件且不重复的四元组。
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes){
    qsort(nums, numsSize, sizeof(int), cmpfunc);
    *returnSize = 0;
    int maxSize = numsSize;
    int **res = calloc(maxSize,sizeof(int *));
    *returnColumnSizes = calloc(maxSize,sizeof(int));
    for(int i=0; i<=numsSize-4; i++){
        if(i!=0 && nums[i]==nums[i-1]) continue;
        for(int j=i+1; j<numsSize; j++){
            if(j!=i+1 && nums[j]==nums[j-1]) continue;
            int L = j+1;
            int R = numsSize-1;
            while(L<R){
                int sum = nums[i]+nums[j]+nums[L]+nums[R];
                if(sum==target){
                    res[*returnSize] = calloc(4,sizeof(int));
                    res[*returnSize][0] = nums[i];
                    res[*returnSize][1] = nums[j];
                    res[*returnSize][2] = nums[L];
                    res[*returnSize][3] = nums[R];
                    (*returnColumnSizes)[*returnSize] = 4;
                    (*returnSize)++;
                    if (*returnSize==maxSize){
                        maxSize += numsSize;
                        res = realloc(res, maxSize * sizeof(int *));
                        *returnColumnSizes = realloc(*returnColumnSizes, maxSize * sizeof(int));
                    }
                    while(L+1<R & nums[L]==nums[L+1]) L++;
                    while(L+1<R & nums[R]==nums[R-1]) R--;
                    R--;
                    L++;
                }else if(sum>target){
                    R--;
                }else{
                    L++;
                }
            }
        }
    }
    return res;
}

///给定一个仅包含数字 2-9 的字符串，
//返回所有它能表示的字母组合。答案可以按 任意顺序 返回。
//给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void backtrace(char **phone, char **res, int *resSize, char *path, char *digits){
    if(strlen(digits)==0){
        res[*resSize] = calloc(strlen(path)+1,sizeof(char));
        strcpy(res[*resSize], path);
        (*resSize)++;
    }else{
        for(int j=0;j<strlen(phone[digits[0]-50]);j++){
            path[strlen(path)] = phone[digits[0]-50][j];
            backtrace(phone, res, resSize, path, digits+1);
        }
    }
    if(strlen(path)>0){
        path[strlen(path)-1]='\0';
    }
}
char ** letterCombinations(char * digits, int* returnSize){
    char *phone[] = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    char *path = calloc(strlen(digits)+1,sizeof(char));
    char **res = calloc(pow(4,strlen(digits)),sizeof(char *));
    *returnSize = 0;
    if(strlen(digits)==0) {
        free(path);
        return res;
    }
    backtrace(phone, res, returnSize, path, digits);
    free(path);
    return res;
}


//给定一个包括 n 个整数的数组 nums 和 一个目标值 target。
//找出 nums 中的三个整数，使得它们的和与 target 最接近。
//返回这三个数的和。假定每组输入只存在唯一答案。
int threeSumClosest(int* nums, int numsSize, int target){
    int best_diff = nums[0]+nums[1]+nums[2]-target;
    qsort(nums, numsSize, sizeof(int), cmpfunc);
    for(int i=0; i<=numsSize-3; i++){
        if(i>0 && nums[i]==nums[i-1]) continue;
        int L = i + 1;
        int R = numsSize-1;
        while(true){
            if(R<=L) break;
            int diff = nums[i] + nums[L] + nums[R] - target;
            if(abs(diff)<abs(best_diff)) best_diff = diff;
            if(diff==0) {
                return target;
            }else if(diff>0){
                R--;
            }else{
                L++;
            }
        }
    }
    return best_diff + target;
}

// 给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，
// 使得 a + b + c = 0 ？请你找出所有和为 0 且不重复的三元组。
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    qsort(nums, numsSize, sizeof(int), cmpfunc);
    int negNums = 0;
    while (negNums<numsSize){
        if(nums[negNums]>0) break;
        negNums++;
    }
    *returnSize = 0;
    *returnColumnSizes = calloc(pow(negNums,2),sizeof(int));
    int **res = calloc(pow(negNums,2), sizeof(int *));
    if(numsSize<3) return 0;

    for(int i=0; i<=numsSize-3; i++){
        if(i>0 && nums[i]==nums[i-1]) continue;
        int L = i+1;
        int R = numsSize-1;
        while(true){
            if(R<=L) break;
            int sum = nums[i]+nums[L]+nums[R];
            if(sum==0){
                res[*returnSize] = calloc(3, sizeof(int));
                res[*returnSize][0] = nums[i];
                res[*returnSize][1] = nums[L];
                res[*returnSize][2] = nums[R];
                (*returnColumnSizes)[*returnSize] = 3;
                (*returnSize)++;
                while(L+1 < R && nums[L+1]==nums[L]) L++;
                while(R-1 > L && nums[R-1]==nums[R]) R--;
                L++;
                R--;
            }else if(sum>0){
                R--;
            }else{
                L++;
            }
        }
    }
    return res;
}




int myAtoi(char * s){
    bool flag = false; // 标记开头
    int sign = 1;
    int n = strlen(s);
    if (n==0) return 0;
    //int nums[n];
    int k = 0; // nums 开始索引
    int j = 0; // nums 结束索引
    int out = 0; 
    for(int i=0; i<n; i++){
        j = i;
        if(s[i]!=' '){
            if(flag==false){ // 开头处理
                flag = true;
                if ((s[i]<48 || s[i]>57) && s[i] != '-' && s[i] != '+') {
                    return 0;
                }else if(s[i] == '-'){
                    sign = -1;
                    k = i+1;
                }else if(s[i]=='+'){
                    sign = 1;
                    k = i+1;
                }else{
                    k = i;
                }
            }else{ // 结尾处理
                if (s[i]<48 || s[i]>57) {
                    j--;
                    break;
                }
            }
        }else if(flag==true) {
            j--;
            break;
        }
    }
    if(flag==false) return 0;
    for(int i=k; i<j+1; i++){
       out +=  pow(10,i-k) * (s[k+j-i]-48);
    }
    if (out==-2147483648) {
        if(sign==-1){
            return out;
        }else{
            return 2147483647;
        }
    }
    out = sign * out;
    return out;
}

/**
 *给你一个整数 x ，如果 x 是一个回文整数，返回 true ；否则，返回 false 。
 回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。例如，121 是回文，而 123 不是。
 */
bool isPalindrome(int x){
    if (x<0) return false;
    if (x==0) return true;
    int nums[10];
    int i = 0;
    while(x>0){
        int q = x / 10;
        int r = x % 10;
        x = q;
        nums[i++] = r;
    }
    if (i%2==1){
        int mid = i / 2;
        for(int j=0; j< mid; j++){
            if (nums[j] != nums[2*mid-j]) return false;
        }
    }else{
        int mid2 = i / 2; // 0, 1, 2, 3, 4, 5
        int mid1 = mid2 -1 ;
        for(int j=0; j<= mid1; j++){
            if(nums[j] != nums[mid1+mid2-j]) return false;
        }
    }
    return true;
}


/*
 *
 * 给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。

'.' 匹配任意单个字符
'*' 匹配零个或多个前面的那一个元素
所谓匹配，是要涵盖 整个 字符串 s的，而不是部分字符串。
输入：s = "aa" p = "a"
输出：false
解释："a" 无法匹配 "aa" 整个字符串。

输入：s = "aa" p = "a*"
输出：true
解释：因为 '*' 代表可以匹配零个或多个前面的那一个元素, 在这里前面的元素就是 'a'。因此，字符串 "aa" 可被视为 'a' 重复了一次。

输入：s = "ab" p = ".*"
输出：true
解释：".*" 表示可匹配零个或多个（'*'）任意字符（'.'）。

输入：s = "aab" p = "c*a*b"
输出：true
解释：因为 '*' 表示零个或多个，这里 'c' 为 0 个, 'a' 被重复一次。因此可以匹配字符串 "aab"。

输入：s = "mississippi" p = "mis*is*p*."
输出：false
 */


/**
 * 正则表达式转成有向图
 * c*a*b
 */
pattern * pattern_compile(char * p){
    int n = strlen(p);
    int star_count = 0;
    for(int i=0; i<n; i++){
        if(p[i] == '*'){
            star_count ++;
        }
    }
    int ns = n - star_count + 1; // 节点数
    pattern * pat = malloc(sizeof(pattern));
    pat->graph = calloc(ns * ns, sizeof(char));
    pat->status = 0;
    pat->num_nodes = ns;
    int j = 0;
    for(int i=0; i<n; i++){
        if(p[i]=='*') continue;
        if(i+1<n && p[i+1] =='*'){
            pat->graph[j*ns+j] = p[i];
            pat->graph[j*ns+j+1] = '*';
        }else{
            pat->graph[j*ns+j+1] = p[i];
        }
        j++;
    }
    for(int i=0; i<ns; i++){
        for(int j=0; j<ns; j++){
            char c = pat->graph[i*ns+j];
            if(c == 0){
                c = '#';
            }
            printf("%c ",c);
        }
        printf("\n");
    }
    return pat;
}

/**
c*a*b 匹配 aab
c @ # # 
# a @ # 
# # # b 
# # # # 

a*
a @
# #
 */
bool subMatch(char * s, int loc, pattern * pat, int status){
    printf("%c : %d,%d\n",s[loc],loc,status);

    int n = strlen(s); 

    if(status == pat->num_nodes-1 && loc <n) return false;

    char ch0 = pat->graph[status * pat->num_nodes + status];
    char ch1 = ' ';
    if (status+1 < pat->num_nodes){
        ch1 = pat->graph[status * pat->num_nodes + status + 1];
    }


    if(loc ==n) {
        if(status == pat->num_nodes-1){
            return true;
        }else{
            if(ch1 != '*'){
                return false;    
            }
        }
    }

    if(ch1 != '*'){ // a* 型
        return (ch1 == s[loc] || ch1 == '.') && subMatch(s, loc+1, pat, status+1);
    }else{
        if(loc==n) return subMatch(s, loc, pat, status+1);
        return (ch0 == s[loc] || ch0 == '.') && subMatch(s, loc+1, pat, status) || subMatch(s, loc, pat, status+1);
    }
}

bool isMatch(char * s, char * p){
    int n = strlen(s);
    int m = strlen(p);
    int j = m-1;
    pattern * pat = pattern_compile(p);
    return subMatch(s, 0, pat, 0);
}



#define MIN(x,y) ((x)<(y)?(x):(y))
int maxArea(int* height, int heightSize){
    int max_area = 0;
    int p=0, q=heightSize-1;
    while(q-p>0){
        
    }
    return max_area;
}

char * intToRoman(int num){
    char *p = calloc(16,sizeof(char));
    int i=0;
    while(true){
        if(num>=1000){
            num -= 1000;
            p[i++] = 'M';
        }else if(num>=900){
            num -= 900;
            p[i++] = 'C';
            p[i++] = 'M';
        }else if(num>=500){
            num -= 500;
            p[i++] = 'D';
        }else if(num>=400){
            num -= 400;
            p[i++] = 'C';
            p[i++] = 'D';
        }else if(num>=100){
            num -= 100;
            p[i++] = 'C';
        }else if(num>=90){
            num -= 90;
            p[i++] = 'X';
            p[i++] = 'C';
        }else if(num>=50){
            num -= 50;
            p[i++] = 'L';
        }else if(num>=40){
            num -= 40;
            p[i++] = 'X';
            p[i++] = 'L';
        }else if(num>=10){
            num -= 10;
            p[i++] = 'X';
        }else if(num>=9){
            num -= 9;
            p[i++] = 'I';
            p[i++] = 'X';
        }else if(num>=5){
            num -= 5;
            p[i++] = 'V';
        }else if(num>=4){
            num -= 4;
            p[i++] = 'I';
            p[i++] = 'V';
        }else if(num>=1){
            num -= 1;
            p[i++] = 'I';
        }else{
            break;
        }
    }
    return p;
}


//13. 罗马数字转整数
int romanToInt(char * s){
    int i=0;
    int num = 0;
    while(true){
        if (i==strlen(s)) break;
        if (s[i]=='M'){
           num += 1000; 
           i++;
        }else if(s[i]=='D'){
            num += 500;
            i++;
        }else if(s[i]=='C'){
            if(s[i+1]=='M'){
                num += 900;
                i += 2;
            }else if(s[i+1]=='D'){
                num += 400;
                i += 2;
            }else{
                num += 100;
                i++;
            }
        }else if(s[i]=='L'){
            num += 50;
            i++;
        }else if(s[i]=='X'){
            if(s[i+1]=='C'){
                num += 90;
                i += 2;
            }else if(s[i+1]=='L'){
                num += 40;
                i += 2;
            }else{
                num += 10;
                i++;
            }
        }else if(s[i]=='V'){
            num += 5;
            i++;
        }else if(s[i]=='I'){
            if(s[i+1]=='X'){
                num += 9;
                i += 2;
            }else if(s[i+1]=='V'){
                num += 4;
                i += 2;
            }else{
                num += 1;
                i ++;
            }
        }
    }
    return num;
}

//14. 最长公共前缀
char * longestCommonPrefix(char ** strs, int strsSize){
    int strSize = 256;
    for(int i=0; i<strsSize; i++){
        if (strlen(strs[i])<strSize) strSize = strlen(strs[i]);
    }
    char *comPrefix = (char *)calloc(strSize+1,sizeof(char));
    if(strsSize==1) return strs[0];
    for(int i=0; i<strSize; i++){
        int j=1;
        for(;j<strsSize; j++){
           if(strs[0][i]!=strs[j][i]) {
               break;
           }
        }
        if(j==strsSize){
            comPrefix[i] = strs[0][i];
        }else{
            break;
        }
    }
    return comPrefix;
}

struct ListNode* createListNodes(int* nums, int numSize){
    if (numSize==0) return NULL;
    struct ListNode* head = malloc(sizeof(struct ListNode));
    struct ListNode* current = head;
    head->val = nums[0];
    for(int i=1; i<numSize; i++){
       current->next = malloc(sizeof(struct ListNode));
       current = current->next;
       current->val = nums[i];
    }
    current->next = NULL;
    return head;
}

struct my_struct *users = NULL;    /* important! initialize to NULL */

void add_user(int user_id, char *name) {
    struct my_struct *s;

    s = malloc(sizeof(struct my_struct));
    s->id = user_id;
    strcpy(s->name, name);
    HASH_ADD_INT(users, id, s);  /* id: name of key field */
}


struct ListNode* reverseKGroup(struct ListNode* head, int k){
    ListNode **nodeStack = calloc(k, sizeof(ListNode*));
    ListNode *curr, *tail;
    curr = head;
    tail = NULL;
    head = NULL;
    int i = -1;
    ListNode *r_curr,*r_prev,*r_head;
    while(curr!=NULL || i==k-1){
        if(i==k-1){
            r_curr=r_prev=r_head=NULL;
            while(i>-1){
                r_curr = nodeStack[i];
                r_curr->next = NULL;
                if(r_prev==NULL) {
                    r_head = r_prev = r_curr;
                }else{
                    r_prev->next = r_curr;
                    r_prev = r_curr;
                }
                i--;
            }
            if(tail==NULL){
                head = r_head;
            }else{
                tail->next = r_head;
            }
            tail = r_curr;
        }else{
            nodeStack[++i]=curr;
            curr = curr->next;
        } 
        printf("%s %d: ",__FILE__,__LINE__);
        printNodes(head);
    }
    if(i>-1 && i<k-1){
        tail->next = nodeStack[0];
    }
    free(nodeStack);
    return head;

}


void printIntVec(int* nums, int length){
    for(int i=0; i<length; i++){
        printf("%d ",nums[i]);
    }
    printf("\n");
}

/**
 * 删除[start,end)区间的元素
 * */
int erase(int *nums, int start, int end, int length){
    for(int i=end; i<length; i++){
        nums[start+i-end] = nums[i];
    }
    return length - (end-start);
}

int removeDuplicates(int* nums, int numsSize){
    int slow = 1;
    int fast = 1;

    while(fast<numsSize){
        printIntVec(nums,numsSize);
        if(nums[fast]!=nums[fast-1]){
            nums[slow] = nums[fast];
            slow++;
        }
        fast++;
    }
    return slow;
}

int removeElement(int* nums, int numsSize, int val){
    qsort(nums, numsSize, sizeof(int), cmpfunc);
    int start=-1, end=-1;
    for(int i=0; i<numsSize; i++){
        if(nums[i]==val){
            if(start==-1) {
                start = end = i;
            }else{
                end = i;
            }
        }
    }
    int newLen = -1;
    if(start!=-1){
        newLen = erase(nums, start, end+1, numsSize);
    }
    return newLen;
}
