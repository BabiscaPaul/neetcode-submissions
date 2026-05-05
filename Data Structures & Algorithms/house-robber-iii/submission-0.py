# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rob(self, root: Optional[TreeNode]) -> int:
        # return 2 cases, if we rob curr node, or we don't
        def dfs(root: TreeNode) -> List[int, int]:
            if root is None: return [0, 0]
            left = dfs(root.left)
            right = dfs(root.right)
            
            # if we rob curr node 
            c1 = root.val + left[1] + right[1]
            
            # if we don't rob curr node
            max_left = max(left)
            max_right = max(right)
            c2 = max_left + max_right
            
            return [c1, c2]
        
        return max(dfs(root))