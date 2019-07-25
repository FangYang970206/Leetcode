# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def rotateRight(self, head: ListNode, k: int) -> ListNode:
        if not head:
            return
        if k == 0 or head.next == None:
            return head
        pre, lst, trv, length = head, head, head, 1
        while trv.next != None:
            trv = trv.next
            length += 1
        rotate_len = k % length
        if rotate_len == 0:
            return head
        pre_i, lst_i = 0, 0
        while lst.next != None:
            lst = lst.next
            if lst_i - pre_i == rotate_len:
                pre = pre.next
                pre_i += 1
            lst_i += 1
        new_head = pre.next
        pre.next = None
        lst.next = head
        return new_head
