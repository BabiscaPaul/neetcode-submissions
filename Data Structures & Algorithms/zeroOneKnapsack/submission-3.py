class Solution:
    def maximumProfit(self, profit: List[int], weight: List[int], capacity: int) -> int:
        memo = {}
        
        def dfs(i, remaining_capacity):
            if (i, remaining_capacity) in memo:
                return memo[(i, remaining_capacity)]
            
            if i >= len(profit):
                return 0
            
            option_without = dfs(i + 1, remaining_capacity)
            
            option_with = 0
            if remaining_capacity >= weight[i]:
                option_with = profit[i] + dfs(i + 1, remaining_capacity - weight[i])
            
            result = max(option_without, option_with)
            
            memo[(i, remaining_capacity)] = result
            
            return result
        
        return dfs(0, capacity)
