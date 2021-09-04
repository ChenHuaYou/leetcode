from leetcode import *


if __name__ == '__main__':

    nums = [1,1,1,2,2,2,3,3]
    s = Solution()
    s.printIntVec(nums, len(nums))
    length = s.removeDuplicates(nums)
    s.printIntVec(nums, length)
    

