# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reorderList(self, head: ListNode) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        if not head: return
        slow, fast, vec = head, head, []
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        move_to_vec = slow.next
        while move_to_vec:
            vec.append(move_to_vec)
            move_to_vec = move_to_vec.next
        slow.next, prev = None, head
        while vec:
            tmp = prev.next
            node_move = vec.pop()
            prev.next = node_move
            node_move.next = tmp
            prev = tmp