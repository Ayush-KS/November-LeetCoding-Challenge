# Binary Tree Tilt

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution: 
    tilt = 0
    def findTilt(self, root: TreeNode) -> int:
        
        def helper(root):
            if not root:
                return 0
            left = helper(root.left)
            right = helper(root.right)
            self.tilt += abs(left - right)
            return left + right + root.val
        
        helper(root)
        return self.tilt