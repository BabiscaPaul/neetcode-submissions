from collections import defaultdict

class Solution:
    def lengthOfLongestSubstringTwoDistinct(self, s: str) -> int:
        freq = defaultdict(int)
        l = 0
        longest = 0
        
        for r, ch in enumerate(s):
            freq[ch] += 1
            
            while len(freq.keys()) > 2:
                freq[s[l]] -= 1
                if freq[s[l]] <= 0: freq.pop(s[l])
                l += 1
            
            longest = max(longest, r - l + 1)
        
        return longest