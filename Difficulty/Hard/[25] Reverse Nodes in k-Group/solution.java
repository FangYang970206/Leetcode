/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode reverseKGroup(ListNode head, int k) {
        if (k <= 1 || head == null) return head;
        ListNode dummyhead = new ListNode(0);
        dummyhead.next = head;
        ListNode prev = dummyhead, curr = prev.next, fut = curr;
        while (fut != null) {
            for (int i = 1; i < k; i++) {
                if (fut.next == null)
                    return dummyhead.next;
                fut = fut.next;
            }
            ListNode tmp = fut.next, currNext = curr.next, tmp1 = curr;
            while (curr != fut) {
                currNext = curr.next;
                curr.next = tmp;
                tmp = curr;
                curr = currNext;
            }
            curr = fut.next;
            fut.next = tmp;
            prev.next = fut;
            prev = tmp1;
            fut = curr;
        }
        return dummyhead.next;
    }
}