class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        visited = set()
        ans, res = [], []
        def dfs():
            if len(res) == len(nums):
                ans.append(res.copy())
                return 
            
            for i in range(len(nums)):
                if nums[i] not in visited: 
                    res.append(nums[i])
                    visited.add(nums[i])
                    dfs()
                    popped = res.pop()
                    visited.remove(popped)
        dfs()
        return ans 