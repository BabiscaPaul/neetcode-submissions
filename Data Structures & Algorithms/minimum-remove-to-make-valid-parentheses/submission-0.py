class Solution:
    def minRemoveToMakeValid(self, s: str) -> str:
        stack = []

        for index, char in enumerate(s):
            if char == ')' and len(stack) > 0 and stack[-1][0] == '(':
                stack.pop()
            elif char == '(' or char == ')':
                stack.append([char, index])
        
        not_included_indeces = {index for _, index in stack}
        result = ""

        for index, char in enumerate(s):
            if index not in not_included_indeces:
                result += char
        
        return result