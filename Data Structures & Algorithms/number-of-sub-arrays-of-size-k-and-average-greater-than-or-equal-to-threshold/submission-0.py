# You are given an array of integers arr and two integers k and threshold, return the number of sub-arrays of size k and average greater than or equal to threshold.

# Example 1:

# Input: arr = [2,2,2,2,5,5,5,8], k = 3, threshold = 4
#               0 1 2 3 4 5 6 7
# Output: 3

from typing import List

class Solution:
    def numOfSubarrays(self, arr: List[int], k: int, threshold: int) -> int:
        count = 0
        l = 0
        curr_window_sum = 0
        
        for r, num in enumerate(arr):
            if r >= k:
                curr_window_sum -= arr[l]
                l += 1
                
            curr_window_sum += num
            if r - l + 1 == k:
                window_average = curr_window_sum // (r - l + 1)
                if window_average >= threshold: count += 1
        
        return count