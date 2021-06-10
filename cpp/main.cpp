#include "leetcode.h"

int main(){
	Solution s;
    map<string,int> inputs;

    inputs = {{"PAYPALISHIRING",4},{"A",1}};
    for(auto &x:inputs){
        cout << x.first << "\n";
        cout << s.convert(x.first,x.second) << endl;
        cout << "\n";
    }

}
