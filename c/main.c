#include "leetcode.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(){
    char *nums = "12";
    struct ListNode * head, *p;
    head = p = calloc(1,sizeof(struct ListNode));
    head->val = nums[0] - 48;
    for(int i=1; i<strlen(nums);i++){
       p->next = calloc(1,sizeof(struct ListNode)); 
       p = p->next;
       p->val = nums[i] - 48;
    }
    p = head = removeNthFromEnd(head, 1);
    while(p!=NULL){
        printf("%d ",p->val);
        struct ListNode *tmp = p;
        p = p->next;
        free(tmp);
    }
    printf("\n");
}
