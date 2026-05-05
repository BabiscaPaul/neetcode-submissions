from typing import List

class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        ans, res = [], []
        candidates.sort()
        def dfs(i=0, curr_sum=0) -> None:
            if curr_sum == target:
                ans.append(res.copy())
                return 
            if curr_sum > target or i >= len(candidates):
                return 
            
            res.append(candidates[i])
            dfs(i + 1, curr_sum + candidates[i])
            
            popped = res.pop()
            while i < len(candidates) and candidates[i] == popped: i += 1
            dfs(i, curr_sum)
        
        dfs()
        return ans