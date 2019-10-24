# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def pathSum(self, root: TreeNode, sum: int) -> List[List[int]]:
        paths, path = [], []
        self.pathSumHelper(paths, path, root, sum)
        return paths
    
    def pathSumHelper(self, paths, path, root, sum):
        if root is None: return
        path.append(root.val)
        if not root.left and not root.right and sum == root.val:
            paths.append(path[:])
        self.pathSumHelper(paths, path, root.left, sum-root.val)
        self.pathSumHelper(paths, path, root.right, sum-root.val)
        path.pop()