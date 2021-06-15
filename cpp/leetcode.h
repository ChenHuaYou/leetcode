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

};
