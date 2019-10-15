class Solution:
    def zigzagLevelOrder(self, root: TreeNode) -> List[List[int]]:
        if root is None:
            return []
        res, q, flapper, size = [], collections.deque(), False, 0
        q.append(root)
        while q:
            size = len(q)
            tmp = []
            if flapper:
                while size > 0:
                    root = q.pop()
                    tmp.append(root.val)
                    if root.right is not None:
                        q.appendleft(root.right)
                    if root.left is not None:
                        q.appendleft(root.left)
                    size -= 1
                    if size == 0:
                        res.append(tmp)
            else:
                while size > 0:
                    root = q.popleft()
                    tmp.append(root.val)
                    if root.left is not None:
                        q.append(root.left)
                    if root.right is not None:
                        q.append(root.right)
                    size -= 1
                    if size == 0:
                        res.append(tmp)
            flapper = True if not flapper else False
        return res