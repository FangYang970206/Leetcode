# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isSameTree(self, p: TreeNode, q: TreeNode) -> bool:
        qp, qq = collections.deque(), collections.deque()
        if p is None and q is None:
            return True
        if p is None or q is None:
            return False
        qp.append(p)
        qq.append(q)
        while qp and qq:
            p = qp.popleft()
            q = qq.popleft()
            if p.val != q.val:
                return False
            if p.left is not None and q.left is not None:
                qp.append(p.left)
                qq.append(q.left)
            elif p.left is None and q.left is None:
                pass
            else:
                return False
            if p.right is not None and q.right is not None:
                qp.append(p.right)
                qq.append(q.right)
            elif p.right is None and q.right is None:
                pass
            else:
                return False
        return True