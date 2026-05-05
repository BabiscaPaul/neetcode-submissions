class Solution:
    def maximumProfit(self, profit: List[int], weight: List[int], capacity: int) -> int:
        def dfs(i, curr_profit, curr_capacity):
            if i >= len(profit):
                return curr_profit
            
            #option 1: don't take current item 
            max_without = dfs(i + 1, curr_profit, curr_capacity)

            #option 2: take current item
            max_with = 0
            if curr_capacity >= weight[i]:
                max_with = dfs(i + 1, curr_profit + profit[i], curr_capacity - weight[i])
            
            return max(max_with, max_without)
        
        return dfs(0, 0, capacity)