from leetcode import *


if __name__ == '__main__':

    head = createNodes([2,5,3,4,6,2,2])
    res = Solution().swapPairs(head)
    while res is not None:
        print(res.val)
        res = res.next

