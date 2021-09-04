from leetcode import *


if __name__ == '__main__':

    head = createNodes([1,2,3,4,5,6,7])
    printNodes(head)
    head = Solution().reverseKGroup(head,3)
    printNodes(head)

