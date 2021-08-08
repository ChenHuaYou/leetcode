#include "leetcode.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(){
    int nums0[] = {1,4,5};
    struct ListNode* l1 = createListNodes(nums0,3);

    int nums1[] = {1,3,4};
    struct ListNode* l2 = createListNodes(nums1,3);

    int nums2[] = {2,6};
    struct ListNode* l3 = createListNodes(nums2,2);

    struct ListNode* lists[] = {l1,l2,l3};

    struct ListNode* current = mergeKLists(lists, 3);

    while(current!=NULL){
        printf("%d ",current->val);
        struct ListNode* tmp = current;
        current = current->next;
        free(tmp);
    }
    printf("\n");
}
