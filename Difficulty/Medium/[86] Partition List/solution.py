# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def partition(self, head: ListNode, x: int) -> ListNode:
        less_set, greater_set, tmp = [], [], head
        while tmp is not None:
            if tmp.val < x:
                less_set.append(tmp.val)
            else:
                greater_set.append(tmp.val)
            tmp = tmp.next
        tmp = head
        for i in less_set:
            tmp.val = i
            tmp = tmp.next
        for i in greater_set:
            tmp.val = i
            tmp = tmp.next
        return head