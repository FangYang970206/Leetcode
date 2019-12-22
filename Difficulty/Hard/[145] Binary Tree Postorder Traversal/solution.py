# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def postorderTraversal(self, root: TreeNode) -> List[int]:
        if not root: return []
        todo, nodes, last = [], [], None
        while root or todo:
            if root:
                todo.append(root)
                root = root.left
            else:
                node = todo[-1]
                if node.right and node.right != last:
                    root = node.right
                else:
                    nodes.append(node.val)
                    last = node
                    todo.pop()
        return nodes