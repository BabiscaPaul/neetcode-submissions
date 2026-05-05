# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        if root is None: return []
        
        result = []
        queue = deque([root])
        
        while queue:
            length = len(queue)
            curr_row = []
            
            for _ in range(length):
                curr_node = queue.popleft()
                curr_row.append(curr_node.val)
                if curr_node.left: queue.append(curr_node.left)
                if curr_node.right: queue.append(curr_node.right)
            
            result.append(curr_row[-1])
        
        return result