#include <exception>
#include <iomanip>
#include <fstream>
#include <vector>
#include <numeric>
#include <iostream>
#include <math.h>
#include <memory>
#include <stdlib.h>
#include <map>
#include <regex>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode *createListNodes(vector<int> vec);
void printNodes(ListNode *head);
void freeNodes(ListNode *head);
void printIntVec(vector<int>& nums);


class Pattern{
    public:
        Pattern(string & pattern);
        bool subMatch(string & s, int loc, int status);
    private:
        int num_nodes;
        shared_ptr<char[]> graph = NULL;
};

class Solution{
    public:
        bool checkSubarraySum(vector<int>& nums, int k);
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
        vector<int> twoSum(vector<int>& nums, int target);
        int lengthOfLongestSubstring(string s);
        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2);
        string longestPalindrome(string s);
        string convert(string s, int numRows);
        long reverse(long x);
        bool isMatch(string & s, string & p);
        /*
         * 从数组 a1,...,an 寻找子数组 ai,a(i+1),...,a(j)使得 (j-i)*min(ai,aj)最大
         * 1*min(a1,a2),2*min(a1,a3),...,(n-2)*min(a1,a(n-1)),(n-1)*min(a1,an)
         * 1*min(a2,a3),2*min(a2,a4),...,(n-2)*min(a2,a(n-1))
         */
        int maxArea(vector<int>& height);
        /*
         * 给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。
         * k 是一个正整数，它的值小于或等于链表的长度。
         * 如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。
         */
        ListNode* reverseKGroup(ListNode* head, int k);
        /**
          给你一个有序数组 nums ，请你 原地 删除重复出现的元素，使每个元素 只出现一次 ，
          返回删除后数组的新长度。不要使用额外的数组空间，你必须在 原地 修改输入数组 
          并在使用 O(1) 额外空间的条件下完成。
         **/
        int removeDuplicates(vector<int>& nums);
        /**
          给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，
          并返回移除后数组的新长度。
          不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并 原地 修改输入数组。
          元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素
         **/
        int removeElement(vector<int>& nums, int val) ;
        /**
        给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 
        needle 字符串出现的第一个位置（下标从 0 开始）。如果不存在，则返回  -1 。
        **/
        int strStr(string haystack, string needle);

};

vector<int> kmp_table(string pattern);
