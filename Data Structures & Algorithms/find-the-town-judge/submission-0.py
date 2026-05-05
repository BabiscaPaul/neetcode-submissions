# Input: n = 4, trust = [[1,3],[4,3],[2,3]]
# Output: 3

from typing import List

class Solution:
    def findJudge(self, n: int, trust: List[List[int]]) -> int:
        degrees = {}
        for i in range(1, n + 1):
            degrees[i] = [0, 0]
        
        for n1, n2 in trust:
            degrees[n1][1] += 1
            degrees[n2][0] += 1
        
        for key, val in degrees.items():
            if val[0] == n - 1 and val[1] == 0:
                return key
        
        return -1