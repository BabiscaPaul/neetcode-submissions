from typing import List
import heapq

class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        negative_stones = [-s for s in stones]
        heapq.heapify(negative_stones)
        
        while len(negative_stones) > 1:
            if len(negative_stones) >= 2:
                s1 = -1 * heapq.heappop(negative_stones)
                s2 = -1 * heapq.heappop(negative_stones)
                
                diff = abs(s1 - s2)
                if diff > 0: heapq.heappush(negative_stones, -diff)
        
        return 0 if negative_stones == [] else -1 * negative_stones[0]