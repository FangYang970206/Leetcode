# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        if not root:
            return True
        else:
            if root.val == 2**31:
                if root.left != None:
                    return False
                else:
                    root = root.right
            elif root.val == -2**31-1:
                if root.right != None:
                    return False
                else:
                    root = root.left
        return self.isValidBSTHelper(root, -2**31-1, 2**31)
    
    def isValidBSTHelper(self, n, lower_bound, upper_bound):
        if n == None:
            return True
        isValidLeft, isValidRight = False, False
        if n.val >= upper_bound or n.val <= lower_bound:
            return False
        isValidLeft = self.isValidBSTHelper(n.left, lower_bound, n.val)
        isValidRight = self.isValidBSTHelper(n.right, n.val, upper_bound)
        return isValidLeft and isValidRight
