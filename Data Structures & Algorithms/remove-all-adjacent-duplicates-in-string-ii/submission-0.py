class Solution:
    def removeDuplicates(self, s: str, k: int) -> str:
        stack, res = [], ""
        
        for ch in s:
            if len(stack) > 0 and ch == stack[-1][0]:
                stack[-1][1] += 1 
            else: 
                stack.append([ch, 1])
            
            if stack[-1][1] == k: stack.pop()
        
        res = res.join([char * times for char, times in stack])
        return res