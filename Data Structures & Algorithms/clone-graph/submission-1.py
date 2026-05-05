"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

class Solution:
    def cloneGraph(self, node: Optional['Node']) -> Optional['Node']:
        if node is None: 
            return None
        
        clones = {}  # mapping original -> clone
        
        def dfs(node: Node) -> Node:
            if node in clones:
                return clones[node]
            
            # Create the clone immediately and store it
            new_node = Node(node.val)
            clones[node] = new_node
            
            # Clone all neighbors
            for neighbor in node.neighbors:
                new_node.neighbors.append(dfs(neighbor))
            
            return new_node
        
        return dfs(node)