class Solution:
    def isPalindrome(self, s: str) -> bool:
        i, j = 0, len(s) - 1
        s_copy = ""

        for ch in s:
            if ch.isalnum(): s_copy += ch.lower()
        
        i, j = 0, len(s_copy) - 1

        while i < j:
            if s_copy[i] != s_copy[j]: return False
            i += 1
            j -= 1
        
        return True 