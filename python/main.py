from leetcode import *


if __name__ == '__main__':

    node1 = ListNode(1)
    node1.next = ListNode(4)
    node1.next.next = ListNode(5)

    node2 = ListNode(1)
    node2.next = ListNode(3)
    node2.next.next = ListNode(4)

    node3 = ListNode(2)
    node3.next = ListNode(6)

    lists = [node1,node2,node3]
    res = Solution().mergeKLists(lists)
    print(res)

