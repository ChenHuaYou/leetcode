#include "leetcode.h"

int main(){
	Solution s;
    vector<long> inputs;

    inputs = {123,-123,120,0,1534236469,9876543219};
    for(auto &x:inputs){
        cout << x << "\n";
        cout << s.reverse(x) << endl;
        cout << "\n";
    }

}
