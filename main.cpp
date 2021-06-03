#include <exception>
#include <iomanip>
#include <fstream>
#include <vector>
#include <numeric>
#include <iostream>


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
int main(){

		int k = 2000000000;

		vector<int> nums = {23,6,9};
		k = 6;
		Solution1 s;
		bool res = s.checkSubarraySum(nums,k);
		cout << res << endl;
}
