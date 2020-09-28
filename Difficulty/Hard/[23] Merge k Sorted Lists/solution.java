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
    public ListNode mergeKLists(ListNode[] lists) {
        if (lists.length == 0) return null;
        if (lists.length == 1) return lists[0];
        return mergeKListsHelper(lists, 0, lists.length - 1);
    }

    public ListNode mergeKListsHelper(ListNode[] lists, int i, int j) {
        if (i == j) return lists[i];
        int mid = (i + j) / 2;
        ListNode l1 = mergeKListsHelper(lists, i, mid);
        ListNode l2 = mergeKListsHelper(lists, mid+1, j);
        return merge(l1, l2);
    }

    public ListNode merge(ListNode l1, ListNode l2) {
        if (l1 == null && l2 == null) return null;
        if (l1 == null || l2 == null) return l1 != null ? l1 : l2;
        if (l1.val > l2.val) {
            l2.next = merge(l1, l2.next);
            return l2;
        } else {
            l1.next = merge(l1.next, l2);
            return l1;
        }
    }
}