# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:

    def goodNodes(self, root: TreeNode) -> int:
        good_count = 0
        def dfs(root: TreeNode = root, max_so_far = float('-inf')):
            if root is None:
                return 
            if root.val >= max_so_far:
                nonlocal good_count
                good_count += 1
            max_so_far = max(max_so_far, root.val)
            dfs(root.left, max_so_far)
            dfs(root.right, max_so_far)

        dfs()
        return good_count