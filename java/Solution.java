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
            //System.out.println(stack.size());
            if(stack.size()==k){
                System.out.println("reverse!");
                ListNode r_curr=null, r_prev=null, r_head=null;
                while(!stack.empty()){
                    r_curr = stack.pop();
                    r_curr.next = null;
                    if(r_prev!=null){
                        r_prev.next = r_curr;
                        r_prev = r_prev.next;
                    }else{
                        r_prev = r_curr;
                        r_head = r_curr;
                    }
                }
                if(tail!=null){
                    tail.next = r_head;
                }else{
                    head = r_head;
                }
                tail = r_curr;
            }else{
                stack.push(curr);
                curr = curr.next; 
            }            
            //System.out.println(curr);
            //printNodes(head);
            //System.out.println(curr.val);
        }
        while(!stack.empty()){
            tail.next = stack.pop();
        }
        //printNodes(head);
        return head;
    }
    public ListNode createNodes(ArrayList<Integer> nums){
        ListNode head=null, curr=null;
        for(int i=0; i<nums.size();i++){
            if(curr!=null){
                curr.next = new ListNode(nums.get(i));
                curr = curr.next;
            }else{
                curr = head = new ListNode(nums.get(i));
            }
            System.out.println(curr);
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
    /**
     *给你一个有序数组 nums ，请你 原地 删除重复出现的元素，
     *使每个元素 只出现一次 ，返回删除后数组的新长度。
     *不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。
     **/
    void printIntVec(int[] nums, int length){
        for(int i=0; i<length; i++){
            System.out.print(nums[i]+" ");
        }
        System.out.print("\n");
    }
    int erase(int nums[], int start, int end, int length){
        for(int i=end+1; i<nums.length; i++){
            nums[start+i-end] = nums[i];
        }
        return length - (end-start);
    }

    public int removeDuplicates(int[] nums) {
        int slow = 1;
        int fast = 1;
        int numsSize = nums.length;

        while(fast<numsSize){
            printIntVec(nums,numsSize);
            if(nums[fast]!=nums[fast-1]){
                nums[slow] = nums[fast];
                slow++;
            }
            fast++;
        }
        return slow;
    }
    /**
      给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，
      并返回移除后数组的新长度。
      不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并 原地 修改输入数组。
      元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素
     **/
    public int removeElement(int[] nums, int val) {
        Arrays.sort(nums);
        int start=-1, end=-1;
        for(int i=0; i<nums.length; i++){
            if(nums[i]==val){
                if(start==-1) {
                    start = end = i;
                }else{
                    end = i;
                }
            }
        }
        int newLen = nums.length;
        if(start!=-1){
            newLen = erase(nums, start-1, end, nums.length);
        }
        return newLen;
    }
    int[] kmp_table(String pattern){
        int pos = 1;
        int cnd = 0;
        int[] T = new int[pattern.length()];
        T[0] = -1;
        while(pos < pattern.length()){
            if(pattern.charAt(cnd)==pattern.charAt(pos)){
                T[pos] = T[cnd];            
            }else{
                T[pos] = cnd;
                while(cnd>=0 && pattern.charAt(pos) != pattern.charAt(cnd)){
                    cnd = T[cnd];
                }
            }
            pos ++;
            cnd ++;
        }
        return T;
    }
    public int strStr(String haystack, String needle) {
        if(needle.length()==0) return 0;
        int j = 0;
        int k = 0;
        int[] T = kmp_table(needle);
        while(j<haystack.length()){
            if(needle.charAt(k)==haystack.charAt(j)){
                j++;
                k++;
                if(k==needle.length()){
                    return j-k;
                }
            }else{
                k = T[k];
                if(k<0){
                    j++;
                    k++;
                }
            }
        }
        return -1;
    }
    public static void main(String[] args){
        Solution s = new Solution();
        String haystack = "ABC ABCDAB ABCDABCDABDE";
        String needle = "ABCDABD";
        int p = s.strStr(haystack, needle);
        System.out.println("index: "+p);
    }
}
