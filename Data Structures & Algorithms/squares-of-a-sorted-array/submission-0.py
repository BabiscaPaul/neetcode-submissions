from typing import List

class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        pos_nums = [abs(num) for num in nums]
        minimum = min(pos_nums)
        res = [minimum ** 2]
        i, j = 0, 0
        
        for index, num in enumerate(pos_nums):
            if num == minimum: 
                i = index - 1
                j = index + 1
                break
            
        while i >= 0 and j < len(pos_nums):
            if pos_nums[i] <= pos_nums[j]:
                res.append(pos_nums[i] * pos_nums[i])
                i -= 1
            else:
                res.append(pos_nums[j] * pos_nums[j])
                j += 1 
        
        while i >= 0:
            res.append(pos_nums[i] * pos_nums[i])
            i -= 1
        
        while j < len(pos_nums):
            res.append(pos_nums[j] * pos_nums[j])
            j += 1
        
        return res