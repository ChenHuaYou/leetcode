#include "uthash.h"
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

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
