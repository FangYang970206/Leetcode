"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""
class Solution:
    def copyRandomList(self, head: 'Node') -> 'Node':
        m, record, i = dict(), [], 0
        new_head = Node(0)
        tmp, new_tmp = head, new_head
        while tmp:
            new_tmp.next = Node(tmp.val)
            m[tmp] = i
            new_tmp, tmp = new_tmp.next, tmp.next
            record.append(new_tmp)
            i += 1
        tmp = head
        new_tmp = new_head
        while tmp:
            if tmp.random:
                new_tmp.next.random = record[m[tmp.random]]
            else:
                new_tmp.next.random = None
            tmp, new_tmp = tmp.next, new_tmp.next
        return new_head.next