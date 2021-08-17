from leetcode import *


if __name__ == '__main__':

    node1 = ListNode(1)
    node1.next = ListNode(4)
    node1.next.next = ListNode(5)
    node1.next.next.next = ListNode(6)

    res = Solution().swapPairs(node1)
    print(res.val,res.next.val,res.next.next.val,res.next.next.next.val)

