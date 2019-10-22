# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> TreeNode:
        return self.sortedArrayToBSTHelper(nums, 0, len(nums))

    def sortedArrayToBSTHelper(self, nums, begin, end):
        if end - begin < 1:
            return None
        root = TreeNode(nums[(end + begin) // 2])
        root.left = self.sortedArrayToBSTHelper(nums, begin, (begin + end) // 2)
        root.right = self.sortedArrayToBSTHelper(nums, (begin + end) // 2 + 1, end)
        return root