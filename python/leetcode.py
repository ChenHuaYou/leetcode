from typing import List

class ListNode:
 def __init__(self, val=0, next=None):
     self.val = val
     self.next = next

def createNodes(arr:List):
    curr= head = ListNode(arr[0])
    for val in arr[1:]:
        curr.next = ListNode(val)
        curr = curr.next
    return head

def printNodes(head):
    while head is not None:
        print(head.val,end=" ")
        head = head.next
    print("")

class Solution:
    def swapPairs(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        count = 0
        prev = head
        curr = head
        #printNodes(head)
        while curr is not None:
            _next = curr.next
            if _next is not None:
                curr.next = _next.next
                _next.next = curr
                if count == 0:
                    head = _next
                else:
                    prev.next = _next
                    prev = prev.next.next
                curr = curr.next
                count += 1
            else:
                break
            #printNodes(head)
        return head

    def mergeKLists(self, lists):
        import heapq
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """
        h = []
        l = []
        i = 0
        for listNode in lists:
            while listNode is not None:
                heapq.heappush(h,(listNode.val,i))
                l.append(listNode)
                i += 1
                listNode = listNode.next
        p = curr = None
        j = 0
        while j < len(l):
            val, i = heapq.heappop(h)
            if curr is None:
                p = curr = l[i]
            else:
                curr.next = l[i]
                curr = curr.next
            j += 1
        return p

    #数字 n 代表生成括号的对数，请你设计一个函数，
    #用于能够生成所有可能的并且 有效的 括号组合。
    def generateParenthesis(self, n: int) -> List[str]:
        class parenteses:
            def __init__(self,
                    stack:list = [],
                    push:list = [],
                    path:list = [],
                    maxDepth:int = 0,
                    res:list = []
                    ):
                pass
                self.stack = stack
                self.push = push
                self.path = path
                self.maxDepth = 2*maxDepth
                self.res = res
        def backtrace_parenteses(p:parenteses) -> None:

            if len(p.path)==p.maxDepth:
                if len(p.stack)==0:
                    p.res.append(''.join(p.path))
            else:
                p.path.append('(')
                p.stack.append('(')
                p.push.append(1)
                backtrace_parenteses(p)

                if len(p.path)==0:
                    return
                p.path.append(')')
                if len(p.stack)==0:
                    p.stack.append(')')
                    p.push.append(1)
                elif p.stack[-1] == '(':
                    p.stack.pop()
                    p.push.append(-1)
                else:
                    p.stack.append(')')
                    p.push.append(1)
                backtrace_parenteses(p)
            p.path.pop()
            if p.push[-1] == 1:
                p.stack.pop()
                p.push.pop()
            elif p.push[-1] == -1:
                p.stack.append('(')
                p.push.pop()
        p = parenteses(maxDepth=n)
        backtrace_parenteses(p)
        return p.res

    #将两个升序链表合并为一个新的 升序 链表并返回。
    #新链表是通过拼接给定的两个链表的所有节点组成的。
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        if l1 is None:
            return l2
        if l2 is None:
            return l1

        if l1.val > l2.val:
            head = tail = l2
            l2 = l2.next
        else:
            head = tail = l1
            l1 = l1.next

        while (l1 is not None) or (l2 is not None):

            if l1 is None:
                tail.next = l2
                tail = l2
                l2 = l2.next
                continue
            if l2 is None:
                tail.next = l1
                tail = l1
                l1 = l1.next
                continue

            if l1.val > l2.val:
                tail.next = l2
                tail = l2
                l2 = l2.next
            else:
                tail.next = l1
                tail = l1
                l1 = l1.next
        return head
    #给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。
    #k 是一个正整数，它的值小于或等于链表的长度。
    #如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。
    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        nodeStack = []
        curr = head
        tail = None
        head = None
        while curr!=None or len(nodeStack)==k:
            if len(nodeStack)==k:
                r_curr=r_prev=r_head=None
                while bool(nodeStack):
                    r_curr = nodeStack.pop()
                    r_curr.next = None
                    if r_prev==None:
                        r_head = r_prev = r_curr
                    else:
                        r_prev.next = r_curr
                        r_prev = r_curr
                if tail==None:
                    head = r_head
                else:
                    tail.next = r_head
                tail = r_curr
            else:
                nodeStack.append(curr)
                curr = curr.next
        if bool(nodeStack):
            tail.next = nodeStack[0]
        return head
    #给你一个有序数组 nums ，请你 原地 删除重复出现的元素，
    #使每个元素 只出现一次 ，返回删除后数组的新长度。
    #不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。
    def erase(self, nums: List[int], start:int, end:int, length:int)->int:
        i = end+1
        while i < length:
            nums[start+i-end] = nums[i]
            i += 1
        return length - (end-start)
    def printIntVec(self, nums:List[int], length:int)->None:
        i = 0
        while i< length:
            print(nums[i],end=" ")
            i += 1
        print("\n")

    def removeDuplicates(self, nums: List[int]) -> int:
        slow = 1
        fast = 1
        numsSize = len(nums)

        while fast<numsSize:
            self.printIntVec(nums,numsSize)
            if nums[fast]!=nums[fast-1]:
                nums[slow] = nums[fast]
                slow += 1
            fast += 1
        return slow
    #  给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，
    #  并返回移除后数组的新长度。
    #  不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并 原地 修改输入数组。
    #  元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素
    def removeElement(self, nums: List[int], val: int) -> int:
        nums.sort()
        start=-1;end=-1;
        for i,e in enumerate(nums):
            if nums[i]==val:
                if start==-1:
                    start = end = i
                else:
                    end = i
        newLen = len(nums);
        if start!=-1:
            newLen = self.erase(nums, start-1, end, len(nums));
        return newLen;

    def kmp_table(self,pattern:str)->List[int]:
        pos:int = 1;
        cnd:int = 0;
        T:List[int] = [0]*len(pattern)
        T[0] = -1;
        patternSize:int = len(pattern);
        while pos < patternSize:
            if pattern[cnd]==pattern[pos]:
                T[pos] = T[cnd]
            else:
                T[pos] = cnd
                while cnd>=0 and pattern[pos] != pattern[cnd]:
                    cnd = T[cnd];
            pos += 1
            cnd += 1
        return T
    def strStr(self, haystack: str, needle: str) -> int:
        haystackSize:int = len(haystack)
        needleSize:int = len(needle);
        if needleSize==0:
            return 0
        j:int = 0;
        k:int = 0;
        m:int = -1;
        T:List[int] = self.kmp_table(needle);
        while j<haystackSize:
            if needle[k]==haystack[j]:
                j += 1
                k += 1
                if k==needleSize:
                    m = j-k
                    break
            else:
                k = T[k]
                if k<0:
                    j += 1
                    k += 1
        return m
