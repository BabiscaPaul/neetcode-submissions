class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        from collections import defaultdict

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        freq_map = defaultdict(int)
        l, max_window = 0, 0
        for r, char in enumerate(s):
            freq_map[char] += 1
            while freq_map[char] > 1:
                freq_map[s[l]] -= 1
                l += 1
            max_window = max(max_window, r - l + 1)
        return max_window