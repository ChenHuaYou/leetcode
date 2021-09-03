#include "leetcode.h"

int main(){
	Solution s;
    vector<int> inputs = {1,2,3,4,5,6};
    ListNode *head = createListNodes(inputs);
    printNodes(head);
    head = s.reverseKGroup(head, 3);
    printNodes(head);
    freeNodes(head);
}
