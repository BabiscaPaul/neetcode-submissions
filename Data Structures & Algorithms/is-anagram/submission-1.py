from collections import defaultdict

class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        dic_s = defaultdict(int)
        dic_t = defaultdict(int)

        for ch1 in s:
            dic_s[ch1] += 1
        for ch2 in t:
            dic_t[ch2] += 1
        
        return dic_s == dic_t
