class Solution:
    def validTree(self, n: int, edges: List[List[int]]) -> bool:
        visited = set()
        adj_list = defaultdict(list)
        
        for u, v in edges:
            adj_list[u].append(v)
            adj_list[v].append(u)

        def dfs(start: int, parent: int):
            if start in visited: return True
            visited.add(start)

            for neighbor in adj_list[start]:
                if neighbor == parent: continue
                if dfs(neighbor, start): return True 
            
            return False
        
        if dfs(0, -1): return False
        for v in range(n):
            if v not in visited: return False 
        return True