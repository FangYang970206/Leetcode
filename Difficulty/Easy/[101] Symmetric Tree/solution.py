class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        if root is None:
            return True
        if root.left is None and root.right is None:
            return True
        if root.left is None or root.right is None:
            return False
        dl, dr = collections.deque(), collections.deque()
        dl.append(root.left)
        dr.append(root.right)
        while dl and dr:
            l = dl.popleft()
            r = dr.popleft()
            if l.val != r.val:
                return False
            if l.left is not None and r.right is not None:
                dl.append(l.left)
                dr.append(r.right)
            elif l.left is None and r.right is None:
                pass
            else:
                return False
            if l.right is not None and r.left is not None:
                dl.append(l.right)
                dr.append(r.left)
            elif l.right is None and r.left is None:
                pass
            else:
                return False
        return True