from typing import List
import math

class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        def can_finish_piles(eating_rate: int) -> bool:
            hrs_count = 0
            for pile in piles:
                hrs_count += math.ceil(pile / eating_rate)
            return hrs_count <= h
        
        l, r = 1, max(piles)
        curr_rate = 0
        final_rate = 0
        
        while l <= r: 
            curr_rate = (l + r) // 2
            
            if can_finish_piles(curr_rate): 
                final_rate = curr_rate
                r = curr_rate - 1
            else: l = curr_rate + 1
            
        return final_rate