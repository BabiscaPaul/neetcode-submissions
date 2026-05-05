from typing import List
from collections import defaultdict

class Solution:
    def singleNumber(self, nums: List[int]) -> List[int]:
        freq = defaultdict(int)
        result = []
        
        for num in nums:
            freq[num] += 1
            
        for key, val in freq.items():
            if val == 1: result.append(key)
        
        return result