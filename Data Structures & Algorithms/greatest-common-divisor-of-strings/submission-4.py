class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        sol = str1 if len(str1) < len(str2) else str2

        for i in range(len(sol) - 1, -1, -1):
            sol = sol[:i + 1]
            multiply_factor_1 = len(str1) // len(sol)
            multiply_factor_2 = len(str2) // len(sol)
            res1 = sol * multiply_factor_1
            res2 = sol * multiply_factor_2
            if res1 == str1 and res2 == str2: return sol
        
        return ""