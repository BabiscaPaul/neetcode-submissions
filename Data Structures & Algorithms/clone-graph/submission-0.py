"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

class Solution:
    def cloneGraph(self, node: Optional['Node']) -> Optional['Node']:
        if node is None: return node 
        
        clones = {} # mapping original -> clone
        
        def dfs(node: Node, parent=None) -> Node:    
            if node in clones: return clones[node]
            
            if node.neighbors == []: 
                new_node = Node(node.val, [parent]) if parent else Node(node.val, [])
                clones[node] = new_node
                return new_node
            
            neighbors = []
            new_node = Node(node.val)
            clones[node] = new_node
            
            for neighbor in node.neighbors:
                neighbors.append(dfs(neighbor, node))
            
            new_node.neighbors = neighbors
            return new_node
            
        return dfs(node)