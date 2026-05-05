class Solution:
    def decodeString(self, s: str) -> str:
        stack = []

        for ch in s:
            if ch != ']':
                stack.append(ch)
            else:
                sub_str = ""
                while stack and stack[-1] != '[':
                    sub_str = stack.pop() + sub_str
                stack.pop()
                constant = ""
                while stack and stack[-1].isdigit():
                    constant = stack.pop() + constant
                sub_str *= int(constant)
                stack.append(sub_str)
        
        return "".join(stack)