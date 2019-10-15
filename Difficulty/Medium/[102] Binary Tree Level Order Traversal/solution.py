# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        if root is None:
            return []
        res, q, size = [], collections.deque(), 0
        q.append(root)
        while q:
            size = len(q)
            tmp = []
            while size > 0:
                ptr = q.popleft()
                if ptr.left is not None:
                    q.append(ptr.left)
                if ptr.right is not None:
                    q.append(ptr.right)
                tmp.append(ptr.val)
                size -= 1
                if size == 0:
                    res.append(tmp)
        return res