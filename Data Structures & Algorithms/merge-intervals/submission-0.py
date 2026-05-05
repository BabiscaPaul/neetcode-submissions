from typing import List

class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        if len(intervals) == 1: return intervals
        
        intervals.sort(key=lambda x: x[0])
        merged_intervals = [[intervals[0][0], intervals[0][1]]]
        
        for start, end in intervals:
            if merged_intervals[-1][0] <= start <= merged_intervals[-1][1]:
                merged_intervals[-1][1] = max(end, merged_intervals[-1][1])
            else: merged_intervals.append([start, end])
        
        return merged_intervals