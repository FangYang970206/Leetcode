# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def sortedListToBST(self, head: ListNode) -> TreeNode:
        if head is None:
            return None
        return self.sortedListToBSTHelper(head, None)
        
    def sortedListToBSTHelper(self, head, tail):
        slow = head
        fast = head
        if head == tail:
            return None
        while fast is not tail and fast.next is not tail:
            slow = slow.next
            fast = fast.next.next
        root = TreeNode(slow.val)
        root.left = self.sortedListToBSTHelper(head, slow)
        root.right = self.sortedListToBSTHelper(slow.next, tail)
        return root