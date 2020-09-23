/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public int carry = 0;
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {        
        return addTwoNumbersHelper(l1, l2);
    }

    public ListNode addTwoNumbersHelper(ListNode l1, ListNode l2) {
        if (l1 == null) return processCarry(l2);
        if (l2 == null) return processCarry(l1);
        ListNode root = new ListNode(0);
        int val = l1.val + l2.val + carry;
        root.val = val % 10;
        carry = val / 10;
        root.next = addTwoNumbersHelper(l1.next, l2.next);
        return root;
    }

    public ListNode processCarry(ListNode l) {
        if (carry == 0) return l;
        if (l == null) {
            return new ListNode(1);
        } else {
            ListNode prev = l, tmp = l;
            while (tmp != null && carry == 1) {
                int val = tmp.val + carry;
                tmp.val = val % 10;
                carry = val / 10;
                prev = tmp;
                tmp = tmp.next;
            }
            if (carry == 1) {
                prev.next = new ListNode(1);
            }
        }
        return l;
    }
}