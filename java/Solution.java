import java.util.*;

//Definition for singly-linked list.
class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

class Solution {
    /**
     *给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。
     *k 是一个正整数，它的值小于或等于链表的长度。
     *如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。
     **/
    public ListNode reverseKGroup(ListNode head, int k) {
        ListNode curr=head, tail=null;
        Stack<ListNode> stack= new Stack<ListNode>();
        while(curr != null || stack.size()==k){
            if(stack.size()==k){
                ListNode r_curr=null, r_prev=null;
                while(!stack.empty()){
                    r_curr = stack.pop();
                    r_curr.next = null;
                    if(r_prev!=null){
                        r_prev.next = r_curr;
                        r_prev = r_prev.next;
                    }else{
                        r_prev = r_curr;
                        head = r_curr;
                    }
                }
                if(tail!=null){
                    tail.next = head;
                }
                tail = r_curr;
            }else{
                stack.push(curr);
            }            
            curr = curr.next; 
        }
        return head;
    }
    public ListNode createNodes(ArrayList<Integer> nums){
        ListNode head=null, curr=null;
        for(int i=0; i<nums.size();i++){
            if(curr!=null){
                curr.next = new ListNode(nums.get(i));
                System.out.println(curr);
            }else{
                curr = head = new ListNode(nums.get(i));
            }
        }
        curr.next = null;
        return head; 
    }
    public void printNodes(ListNode head){
        while(head!=null){
            System.out.print(head.val+" ");
            head = head.next;
        }
        System.out.print("\n");
    }
    public static void main(String[] args){
        ArrayList<Integer> nums = new ArrayList<Integer>();
        nums.add(1);
        nums.add(2);
        nums.add(3);
        nums.add(4);
        nums.add(5);
        nums.add(6);
        Solution solution = new Solution();
        ListNode head = solution.createNodes(nums);
        solution.printNodes(head);
        System.out.println("你好!");
    }
}
