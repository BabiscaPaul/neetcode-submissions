from typing import List

class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort() # O(N*logN)
        res = []
        
        for i in range(len(nums) - 2):
            if i > 0 and nums[i] == nums[i - 1]: continue
            j, k = i + 1, len(nums) - 1
            need = -nums[i]
            
            while j < k:
                if nums[j] + nums[k] == need:
                    res.append([nums[i], nums[j], nums[k]])
                    j += 1
                    k -= 1

                    while j < k and k < len(nums) - 1 and nums[k] == nums[k + 1]: k -= 1
                    while j < k and nums[j] == nums[j - 1]: j += 1

                else:
                    if nums[j] + nums[k] > need: k -= 1
                    else: j += 1 
        
        return res