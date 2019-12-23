# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def insertionSortList(self, head: ListNode) -> ListNode:
        if not head: return None
        prev, next, cur, new_head = head, None, head.next, ListNode(0)
        new_head.next = head
        while cur:
            if cur.val >= prev.val:
                prev = cur
                cur = cur.next
            else:
                next = cur.next
                cur.next = None
                prev.next = next
                tmp_prev, tmp = new_head, new_head.next
                while 1:
                    if tmp.val > cur.val:
                        tmp_prev.next = cur
                        cur.next = tmp
                        break
                    else:
                        tmp_prev = tmp
                        tmp = tmp.next
                cur = next
        return new_head.next