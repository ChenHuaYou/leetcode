#include "leetcode.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(){
    struct ListNode* head = createNodes(5,1,2,3,4,5);
    printNodes(head);
    head = swapPairs(head);
    printNodes(head);
    freeNodes(head);
}
