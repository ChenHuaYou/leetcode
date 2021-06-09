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

class Solution4 {
    public:
        int lengthOfLongestSubstring(string s) {
            map<char,int> mymap;
            int count = 0, maxv = 0, start=0;
            for(int i=0; i<s.size(); i++){
                int j = mymap[s[i]];
                mymap[s[i]] = i+1;
                if(j==0){
                    count ++;
                }else{
                    start = max(j, start);
                    count = i + 1 - start;
                }
                if(count>maxv) maxv=count;
            }
            return maxv;
        }
};

class Solution5 {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int p=0, q=0;
        int left=0, right=0;
        vector<int> new_nums;
        double res = 0;
        while(true){
            if(p==nums1.size()){
               left = 1e6; 
            }else{
                left = nums1[p];
            }
            if(q==nums2.size()){
               right = 1e6; 
            }else{
                right = nums2[q];
            }
            if(p==nums1.size() && q==nums2.size()){
                break;
            }
            if (left>right){
                new_nums.push_back(right);
                if(q!=nums2.size()) q++;
            }else{
                new_nums.push_back(left);
                if(p!=nums1.size()) p++;
            }
        }
		if(new_nums.size()%2==0){
			res = ((double)new_nums[new_nums.size()/2-1]+(double)new_nums[new_nums.size()/2])/2;
		}else{
			res = (double)new_nums[new_nums.size()/2];
		}
		return res;
	}
};

class Solution {
    public:
        string longestPalindrome(string s) {
            string ss ="";
            for(int i=0; i<s.size(); i++){
                if (i==0){
                    ss.push_back('^');
                }else{
                    ss.push_back('#');
                }
                ss.push_back(s[i]);
            }
            ss.push_back('$');
            int* P = new int[ss.size()];
            int L = 0;
            int R = -1;
            for (int i=0; i<ss.size(); i++){
                P[i] = 0;
                if(i<=R){
                    P[i] = min(P[L+R-i],R-i);
                }
                int left = i-P[i]-1;
                int right = i+P[i]+1;
                while(left>=0 && right<ss.size() && ss[left]==ss[right]){
                    P[i] ++;
                    left --;
                    right ++;
                }
                if(i+P[i]>R){
                    L = i-P[i];
                    R = i+P[i];
                }
            }
            int c = 0;
            int radius = 0;
            for(int i=0; i<ss.size(); i++){
                cout << P[i] << " ";
                if(radius<P[i]){
                    radius = P[i];
                    c = i;
                }
            }
            ss = ss.substr(c-radius,2*radius+1);
            if(ss.compare("^")==0){
                return s.substr(0,1);
            }
            ss = regex_replace(ss, std::regex("\\#|\\^|\\$"), "");
            return ss;
        }
};

int main(){
	Solution s;
    vector<string> inputs;

    inputs = {"babad","cbbd","a","ac","aacabdkacaa"};
    for(int i=0; i<inputs.size();i++){
        cout << inputs[i] << "\n";
        cout << s.longestPalindrome(inputs[i]) << endl;
        cout << "\n";
    }

}
