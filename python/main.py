from leetcode import *


if __name__ == '__main__':
    s = Solution()
    haystack:str = "ABC ABCDAB ABCDABCDABDE"
    needle:str = "ABCDABD"
    index:int = s.strStr(haystack, needle)
    print("index is : "+str(index))

    

