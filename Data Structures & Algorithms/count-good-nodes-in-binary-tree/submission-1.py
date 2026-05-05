# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        curr_path = []
        count = 0
        def dfs(root: TreeNode):
            nonlocal count
            if root is None: return
            
            curr_path.append(root.val)
            maximum = max(curr_path)
            if root.val >= maximum: count += 1
            
            dfs(root.left)
            dfs(root.right)

            curr_path.pop()
        dfs(root)
        return count