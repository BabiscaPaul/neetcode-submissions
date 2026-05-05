from typing import List

class Solution:
    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        adj_list = {i: [] for i in range(len(isConnected))}
        prov_count = 0
        visited = set()
        
        for i in range(len(isConnected)):
            for j in range(len(isConnected)):
                if i != j and isConnected[i][j] == 1: 
                    adj_list[i].append(j)
        
        def dfs(start: int) -> None:
            if start in visited: return
            
            visited.add(start)
            for neighbor in adj_list[start]:
                if neighbor not in visited: 
                    dfs(neighbor)
                    
        for i in range(len(isConnected)):
            if i not in visited:
                dfs(i)
                prov_count += 1
        
        return prov_count