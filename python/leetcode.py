

class ListNode:
 def __init__(self, val=0, next=None):
     self.val = val
     self.next = next

class Solution21:
    #将两个升序链表合并为一个新的 升序 链表并返回。
    #新链表是通过拼接给定的两个链表的所有节点组成的。
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        if l1 is None:
            return l2
        if l2 is None:
            return l1

        if l1.val > l2.val:
            head = tail = l1
        else:
            head = tail = l2

        while (l1 is not None) or (l2 is not None):

            if l1 is None:
                tail.next = l2
                tail = l2
                l2 = l2.next
            if l2 is None:
                tail.next = l1
                tail = l1
                l1 = l1.next

            if l1.val > l2.val:
                tail.next = l2
                tail = l2
                l2 = l2.next
            else:
                tail.next = l1
                tail = l1
                l1 = l1.next
