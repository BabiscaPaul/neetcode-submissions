class Solution:
    def reverse(self, x: int) -> int:
        is_positive = x > 0
        copy_x = abs(x)
        digits = []
        reversed_x = 0
        
        while copy_x:
            digits.append(copy_x % 10)
            copy_x //= 10 
        
        for digit in digits:
            reversed_x += digit
            reversed_x *= 10
        reversed_x //= 10
        if not is_positive: reversed_x = -reversed_x
        print(reversed_x)
        
        if reversed_x <= -(2**31) or reversed_x >= 2**31 - 1: return 0
        return reversed_x