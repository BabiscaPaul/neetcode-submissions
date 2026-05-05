from typing import List

class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        answer, result = [], []
        def dfs(i=0, curr_sum=0) -> None:
            if curr_sum == target: 
                answer.append(result.copy())
                return
            if i >= len(candidates) or curr_sum > target:
                return 
            
            result.append(candidates[i])
            dfs(i, curr_sum + candidates[i])
            result.pop()
            dfs(i + 1, curr_sum)
        dfs()
        return answer