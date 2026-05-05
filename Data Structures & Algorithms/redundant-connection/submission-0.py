class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        vertices = len(edges)
        visited = set()
        adjacency_list = defaultdict(list)
        
        def dfs(start: int, parent: int) -> bool:
            if start in visited: return True
            
            visited.add(start)
            for neighbor in adjacency_list[start]:
                if neighbor == parent: continue
                if dfs(neighbor, start): return True 
            
            return False
        
        for u, v in edges: 
            visited = set()
            adjacency_list[u].append(v)
            adjacency_list[v].append(u)
            
            if dfs(u, -1): return [u, v]
        
        return []