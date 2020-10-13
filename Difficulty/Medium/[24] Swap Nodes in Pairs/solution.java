/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode swapPairs(ListNode head) {
        if (head == null || head.next == null) return head;
        ListNode dummyHead = new ListNode(0);
        dummyHead.next = head;
        ListNode prev = dummyHead, curr = prev.next, fut = curr.next;
        while (true) {
            ListNode tmp = fut.next;
            curr.next = tmp;
            fut.next = curr;
            prev.next = fut;
            if (curr.next != null && curr.next.next != null) {
                prev = prev.next.next;
                tmp = curr.next.next;
                curr = fut.next.next;
                fut = tmp;
            } else {
                break;
            }
        }
        return dummyHead.next;
    }
}