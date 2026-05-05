class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        stack = [[temperatures[-1], len(temperatures) - 1]]
        res = [0] * len(temperatures)

        for i in range(len(temperatures) - 2, -1, -1):
            curr_temp = temperatures[i]
            while stack and stack[-1][0] <= curr_temp:
                stack.pop()
            if stack: res[i] = abs(stack[-1][1] - i)
            stack.append([curr_temp, i])
        
        return res