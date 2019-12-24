# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def sortList(self, head: ListNode) -> ListNode:
        if not head or not head.next: return head
        slow, fast, prev = head, head, None
        while fast and fast.next:
            prev = slow
            slow = slow.next
            fast = fast.next.next
        prev.next = None
        slow = self.sortList(slow)
        head = self.sortList(head)
        return self.merge(slow, head)

    def merge(self, h1, h2):
        new_head = ListNode(0)
        node = new_head
        while h1 and h2:
            if h1.val > h2.val:
                node.next = h2
                h2 = h2.next
            else:
                node.next = h1
                h1 = h1.next
            node = node.next
        if h1:
            node.next = h1
        if h2:
            node.next = h2
        return new_head.next