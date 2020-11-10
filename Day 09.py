# Maximum Difference Between Node and Ancestor

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxAncestorDiff(self, root: TreeNode) -> int:
        ans = 0
        
        def helper(root):
            nonlocal ans
            imin, imax = root.val, root.val
            if root.left:
                child = helper(root.left)
                imin, imax = min(imin, child[0]), max(imax, child[1])
            if root.right:
                child = helper(root.right)
                imin, imax = min(imin, child[0]), max(imax, child[1])
            ans = max(ans, max(abs(root.val - imin), abs(root.val - imax)))
            return imin, imax
        
        helper(root)
        return ans
        