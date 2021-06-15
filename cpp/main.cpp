#include "leetcode.h"

int main(){
	Solution s;
    vector<string> inputs;
    vector<string> pattern;

    inputs = {
        "abcd"
    };
    pattern = {
        ".*"
    };
    for(auto i=0; i<inputs.size(); i++){
        printf("%s %s\n",inputs[i].c_str(),pattern[i].c_str());
        cout << s.isMatch(inputs[i], pattern[i]) << endl;
        cout << "\n";
    }

}
