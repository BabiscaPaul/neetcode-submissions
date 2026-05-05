from typing import List

class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        def get_result(x: int, y: int, op: str) -> int:
            res = 0
            
            if op == '+': res = x + y
            elif op == '-': res = x - y
            elif op == '*': res = x * y
            else: res = int(x / y)
            
            return res 
        
        stack = []
        operands = {'+', '-', '*', '/'}
        
        for token in tokens:
            if token not in operands:
                stack.append(int(token))
            else:
                y, x = stack.pop(), stack.pop()
                stack.append(get_result(x, y, token))
        
        return stack[-1]