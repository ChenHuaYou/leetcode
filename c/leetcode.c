#include "uthash.h"
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "leetcode.h"
#include "stdio.h"

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
    *returnSize = 0;
    *returnColumnSizes = calloc(numsSize,sizeof(int));
    int **res = calloc(numsSize, sizeof(int *));

    qsort(nums, numsSize, sizeof(int), cmpfunc);
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
                while(nums[L+1]==nums[L]) L++;
                while(nums[R-1]==nums[R]) R--;
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


