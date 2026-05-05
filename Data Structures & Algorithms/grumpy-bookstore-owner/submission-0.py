from typing import List

class Solution:
    def maxSatisfied(self, customers: List[int], grumpy: List[int], minutes: int) -> int:
        satisfied_customers = 0
        max_satisfied_customers = 0
        
        for i, g in enumerate(grumpy):
            if g == 0: satisfied_customers += customers[i]
        
        l = 0
        
        for r, customer in enumerate(customers):
            if r >= minutes:
                satisfied_customers -= customers[l] if grumpy[l] == 1 else 0
                l += 1 
            
            satisfied_customers += customer if grumpy[r] == 1 else 0 
            
            
            max_satisfied_customers = max(max_satisfied_customers, satisfied_customers)
        
        return max_satisfied_customers