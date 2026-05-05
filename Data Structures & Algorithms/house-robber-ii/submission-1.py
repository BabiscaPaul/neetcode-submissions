from typing import List

class Solution:
    def rob(self, nums: List[int]) -> int:
        cache = {}
        
        nums_including_first_house = nums[:len(nums) - 1]
        nums_excluding_first_house = nums[1:len(nums)]
        
        def dfs(i: int, houses: List):
            if i >= len(houses):
                return 0 
            if i in cache:
                return cache[i]
            
            rob = houses[i] + dfs(i + 2, houses)
            skip = dfs(i + 1, houses)
            cache[i] = max(rob, skip)
            
            return cache[i]
        
        if len(nums) == 1: return nums[0]
        c1 = dfs(0, nums_excluding_first_house)
        cache = {}
        c2 = dfs(0, nums_including_first_house)
        return max(c1, c2)