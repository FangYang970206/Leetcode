# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def generateTrees(self, n: int) -> List[TreeNode]:
        return self.generateTreesHelper(1, n) if n > 0 else []

    def generateTreesHelper(self, begin, end):
        if begin > end:
            return [None]
        
        allTrees = []
        for i in range(begin, end + 1):
            leftTrees = self.generateTreesHelper(begin, i - 1)
            rightTrees = self.generateTreesHelper(i + 1, end)
            for lt in leftTrees:
                for rt in rightTrees:
                    curNode = TreeNode(i)
                    curNode.left = lt
                    curNode.right = rt
                    allTrees.append(curNode)
        return allTrees
            