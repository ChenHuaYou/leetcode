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

class Solution{
    public:
        bool checkSubarraySum(vector<int>& nums, int k);
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
        vector<int> twoSum(vector<int>& nums, int target);
        int lengthOfLongestSubstring(string s);
        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2);
        string longestPalindrome(string s);
        string convert(string s, int numRows);

};
