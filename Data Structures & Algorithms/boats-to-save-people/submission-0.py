class Solution:
    def numRescueBoats(self, people: List[int], limit: int) -> int:
        people.sort()
        left, right = 0, len(people) - 1
        boat_count = 0
        
        while left <= right:
            if people[left] + people[right] <= limit:
                left += 1  # Both people board the boat
            right -= 1  # Heaviest person always boards
            boat_count += 1
        
        return boat_count