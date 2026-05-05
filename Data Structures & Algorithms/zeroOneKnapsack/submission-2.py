class Solution:
    def maximumProfit(self, profit: List[int], weight: List[int], capacity: int) -> int:
        # Create our memoization dictionary outside the recursive function
        # This dictionary will store: {(item_index, remaining_capacity) -> max_profit}
        memo = {}
        
        def dfs(i, remaining_capacity):
            # MOMENT 1: Check if we've already solved this subproblem
            # Before doing any work, look up this exact state in our memo
            if (i, remaining_capacity) in memo:
                return memo[(i, remaining_capacity)]
            
            # Base case: no more items to consider
            if i >= len(profit):
                return 0
            
            # Option 1: Don't take the current item
            # Move to next item with same capacity
            option_without = dfs(i + 1, remaining_capacity)
            
            # Option 2: Take the current item (if it fits)
            option_with = 0
            if remaining_capacity >= weight[i]:
                # Add current item's profit + best profit from remaining items
                option_with = profit[i] + dfs(i + 1, remaining_capacity - weight[i])
            
            # Find the better of our two options
            result = max(option_without, option_with)
            
            # MOMENT 2: Store the result before returning it
            # Save this computed result for future lookups
            memo[(i, remaining_capacity)] = result
            
            return result
        
        # Start the recursion from item 0 with full capacity
        return dfs(0, capacity)

# Example trace to understand the memoization:
# Let's say profit = [3, 4, 5], weight = [2, 3, 4], capacity = 5
#
# First call: dfs(0, 5)
#   - Not in memo, so compute
#   - option_without = dfs(1, 5) 
#   - option_with = 3 + dfs(1, 3)
#   - Let's say this evaluates to 7, so memo[(0, 5)] = 7
#
# Later, if we somehow need dfs(0, 5) again:
#   - Check memo: (0, 5) exists with value 7
#   - Immediately return 7 without any computation!
#
# Time Complexity: O(n * capacity) instead of O(2^n)
# Space Complexity: O(n * capacity) for the memo table + O(n) for recursion stack