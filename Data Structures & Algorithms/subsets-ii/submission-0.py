from typing import List

class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        ans, res = [], [] 
        nums.sort() 
        
        def dfs(i=0) -> None:
            if i >= len(nums):
                ans.append(res.copy())
                return 
            
            res.append(nums[i])
            dfs(i + 1)
            popped = res.pop()
            while i < len(nums) and nums[i] == popped: i += 1
            dfs(i)
        
        dfs()
        return ans