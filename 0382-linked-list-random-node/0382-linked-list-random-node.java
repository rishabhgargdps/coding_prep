/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
//reservoir sampling; k/(i+1) | (k/i)*(1-(1/i+1)) | k/(i+1)*(1/k)
    public ListNode head = null;
    public Solution(ListNode head) {
        this.head = head;
    }
    
    public int getRandom() {
        ListNode curr = head;
        int i=1, res = 0;
        while(curr != null) {
            if(Math.random() < (1.0/i)) {
                res = curr.val;
            }
            i++;
            curr = curr.next;
        }
        return res;
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */