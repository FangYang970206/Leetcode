# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        if not head:
            return None
        pre_ptr, move_ptr, num = ListNode(0), head, 0
        pre_ptr.next = head
        new_head = pre_ptr
        while move_ptr.next != None:
            if move_ptr.val == move_ptr.next.val:
                num += 1
                move_ptr = move_ptr.next
                if move_ptr.next == None:
                    pre_ptr.next = move_ptr.next
            else:
                if num > 0:
                    pre_ptr.next = move_ptr.next
                    move_ptr = move_ptr.next
                    num = 0
                else:
                    pre_ptr = pre_ptr.next
                    move_ptr = move_ptr.next
        return new_head.next
        