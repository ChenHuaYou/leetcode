from leetcode import *


if __name__ == '__main__':

    nums = [3,2,2,3]
    s = Solution()
    s.printIntVec(nums, len(nums))
    length = s.removeElement(nums,3)
    s.printIntVec(nums, length)
    

