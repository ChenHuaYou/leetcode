#include "leetcode.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(){
    int nums0[] = {0,2,5};
    struct ListNode* list1 = createListNodes(nums0, 3);
    //int nums1[] = {1,3,4};
    //struct ListNode* list2 = createListNodes(nums1, 3);
    //int nums2[] = {2,6};
    //struct ListNode* list3 = createListNodes(nums2, 2);

    struct ListNode* lists[] = {list1};
    
    struct ListNode* current = mergeKListsByHeapSort(lists, 1);
    while(current!=NULL){
        printf("%d ",current->val);
        struct ListNode* tmp = current;
        current = current->next;
        free(tmp);
    }
    printf("\n");
}
