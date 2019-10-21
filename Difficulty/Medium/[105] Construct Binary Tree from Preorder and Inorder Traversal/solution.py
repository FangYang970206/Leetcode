# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        hash_map = dict()
        for i in range(len(inorder)):
            hash_map[inorder[i]] = i
        return self.buildTreeHelper(0, 0, len(inorder) - 1, preorder, inorder, hash_map)
    
    def buildTreeHelper(self, preStart, inStart, inEnd, preorder, inorder, hash_map):
        if preStart > len(preorder) - 1 or inStart > inEnd:
            return None
        root = TreeNode(preorder[preStart])
        index = hash_map[root.val]
        root.left = self.buildTreeHelper(preStart+1, inStart, index - 1, preorder, inorder, hash_map)
        root.right = self.buildTreeHelper(preStart + index - inStart + 1, index + 1, inEnd, preorder, inorder,hash_map)
        return root