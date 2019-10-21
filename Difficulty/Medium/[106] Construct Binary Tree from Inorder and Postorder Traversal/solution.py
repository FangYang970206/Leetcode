# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> TreeNode:
        hash_map = dict()
        for i in range(len(inorder)):
            hash_map[inorder[i]] = i
        return self.buildTreeHelper(len(postorder) - 1, 0, len(inorder) - 1, inorder, postorder, hash_map)

    def buildTreeHelper(self, postStart, inStart, inEnd, inorder, postorder, hash_map):
        if postStart < 0 or inStart > inEnd:
            return None
        root = TreeNode(postorder[postStart])
        index = hash_map[root.val]
        root.left = self.buildTreeHelper(postStart - (inEnd - index) - 1, inStart, index - 1, inorder, postorder, hash_map)
        root.right = self.buildTreeHelper(postStart - 1, index + 1, inEnd, inorder, postorder, hash_map)
        return root