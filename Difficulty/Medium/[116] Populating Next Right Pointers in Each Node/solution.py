"""
# Definition for a Node.
class Node:
    def __init__(self, val, left, right, next):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""
class Solution:
    def connect(self, root: 'Node') -> 'Node':
        if not root or not root.left: return root
        self.connectNode(root.left, root.right)
        return root
    
    def connectNode(self, leftNode, rightNode):
        leftNode.next = rightNode
        if leftNode.left:
            self.connectNode(leftNode.left, leftNode.right)
            self.connectNode(leftNode.right, rightNode.left)
            self.connectNode(rightNode.left, rightNode.right)