from typing import List
from collections import defaultdict

class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        freq_map = defaultdict(int)
        l = 0 
        window_len = k + 1
        
        for r, num in enumerate(nums):
            freq_map[num] += 1
            if freq_map[num] > 1: return True
            if r - l + 1== window_len:
                freq_map[nums[l]] -= 1
                l += 1
        
        return False