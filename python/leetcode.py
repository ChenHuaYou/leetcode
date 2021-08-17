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
        printNodes(head)
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
            printNodes(head)
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
