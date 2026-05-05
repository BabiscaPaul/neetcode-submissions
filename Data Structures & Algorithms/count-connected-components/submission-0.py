from collections import defaultdict

class Solution:
    def countComponents(self, n: int, edges: List[List[int]]) -> int:
        adjacency_list = defaultdict(list)
        visited = set()
        connected_components = 0
        
        for u, v in edges:
            adjacency_list[u].append(v)
            adjacency_list[v].append(u)

        def dfs(start: int) -> None:
            if start in visited: return 
            visited.add(start)
            for neighbor in adjacency_list[start]:
                dfs(neighbor)
        
        for v in range(n):
            if v not in visited: 
                dfs(v)
                connected_components += 1
        
        return connected_components