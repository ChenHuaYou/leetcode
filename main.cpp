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



using namespace std;


class Solution1 {
/**
* 给你一个整数数组 nums 和一个整数 k ，编写一个函数来判断该数组是否含有同时满足下述条件的连续子数组：
子数组大小 至少为 2 ，且
子数组元素总和为 k 的倍数。
如果存在，返回 true ；否则，返回 false 
*/
public:
    bool checkSubarraySum(vector<int>& nums, int k) {    
            int n = nums.size();  
            int v = accumulate(nums.begin(),nums.end(),0);    
            for(int i=0;i<n-1;i++){       
                int w = v;
                for (int j=n-1;j>i;j--){     
                    if(nums[i]!=0&&w<k) break;        
                    if (w % k==0){  
                            return true;    
                    }    
                    w = w - nums[j];   
                }  
                v = v - nums[i];  
            }    
            return false;    
    }   
};



struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution2 {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		int a = 0;
		int b = 0;
		int c = 0;
		int r = 0;
		int o0 = 0; 
		int o1 = 0;
		ListNode* h = nullptr, *p = nullptr;
		while(true){
			o1 = o0;
			if(l1!=nullptr) {
				a = l1->val;
			}else{
				a = 0;
			}
			if(l2!=nullptr) {
				b = l2->val;
			}else{
				b = 0;
			}
			c = a + b + o1;
			if (c>=10){
				r = c - 10;
				o0 = 1;
			}else{
				r = c;
				o0 = 0;
			}
			if (h==nullptr){
				h = p = new ListNode(r);
			}else{
				p->next = new ListNode(r);
				p = p->next;
			}
			if(l1!=nullptr) l1 = l1->next;
			if(l2!=nullptr) l2 = l2->next;
			if(l1==nullptr && l2==nullptr && o0 == 0) break;
		}
		return h;
    }
    string node2num(ListNode* l){
        string num = "";
        while(l != nullptr){
            num += to_string(l->val);
            l = l->next;
        }
        return num;
    }
	ListNode* num2node(string num){
		ListNode* l = nullptr;
		ListNode* h = nullptr;
		for (char s: num){
			if (h==nullptr){
				h = l = new ListNode(atoi(&s));
			}else{
				l->next = new ListNode(atoi(&s));
				l = l->next;
			}
		}
		return h;
	}  
};

class Solution3 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> mymap;
        vector<int> res;
        int n = nums.size();
        for(int i=0;i<n;i++){
            mymap[nums[i]] = i+1;
        }
        for(int i=0;i<n;i++){
            int other = target - nums[i];
            int other_index = mymap[other];
            if (other_index!=0 && other_index-1 != i){
                res.push_back(i);
                res.push_back(other_index-1); 
                break;
            }
        }
        return res;
    }
};

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> mymap;
        int count = 0, maxv = 0;
        for(int i=0; i<s.size(); i++){
            int j = mymap[s[i]];
            if(j==0){
                mymap[s[i]] = i+1;
				count ++;
            }else{
				mymap.clear();
				mymap[s[i]] = i+1;
				if (count>maxv) maxv = count;
				count = 1;
            }
        }
        return maxv;
    }
};


int main(){
	Solution s;
	string ss = "pwwkew";
	cout << ss << "\n";
	cout << s.lengthOfLongestSubstring(ss) << endl;

	ss = "bbbbb";
	cout << ss << "\n";
	cout << s.lengthOfLongestSubstring(ss) << endl;


	ss = "abcabcbb";
	cout << ss << "\n";
	cout << s.lengthOfLongestSubstring(ss) << endl;


}
