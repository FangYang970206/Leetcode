# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def levelOrderBottom(self, root: TreeNode) -> List[List[int]]:
        if root is None:
            return []
        d, q, res = collections.deque(), collections.deque(), []
        q.append(root)
        while q:
            tmp, size = [], len(q)
            while size > 0:
                ptr = q.popleft()
                tmp.append(ptr.val)
                if ptr.left is not None:
                    q.append(ptr.left)
                if ptr.right is not None:
                    q.append(ptr.right)
                size -= 1
            d.appendleft(tmp)
        for l in d:
            res.append(l)
        return res