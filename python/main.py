from leetcode import *


if __name__ == '__main__':

    solution = Solution()
    l1 = cur = ListNode(1)
    for val in [2,4]:
        cur.next = ListNode(val)
        cur = cur.next
    l2 = cur = ListNode(1)
    for val in [3,4]:
        cur.next = ListNode(val)
        cur = cur.next
    l = solution.mergeTwoLists(l1, l2)

    while l is not None:
        print(l.val)
        l = l.next
