from typing import List

class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        ans, res = [], []
        
        def dfs(i=1):
            if len(res) == k: 
                ans.append(res.copy())
                return 
            
            for j in range(i, n+1):
                res.append(j)
                dfs(j + 1)
                res.pop()
        
        dfs()
        return ans