from typing import List

class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        answer, subset = [], []
        
        def dfs(i=0) -> None:
            if i >= len(nums): 
                answer.append(subset.copy())
                return 
            
            subset.append(nums[i])
            dfs(i + 1)
            subset.pop()
            dfs(i + 1)
        
        dfs()
        return answer