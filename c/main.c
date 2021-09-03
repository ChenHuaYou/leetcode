#include "leetcode.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main(){
    int nums[6] = {1,2,3,4,5,6};
    ListNode *head = createListNodes(nums,6);
    printNodes(head);
    head = reverseKGroup(head, 3);
    printNodes(head);
    freeNodes(head);
}
