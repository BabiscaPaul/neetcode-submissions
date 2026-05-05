from typing import List

class Solution:
    def asteroidCollision(self, asteroids: List[int]) -> List[int]:
        stack = []
        
        for asteroid in asteroids:
            while stack and asteroid < 0 and stack[-1] > 0:
                if stack[-1] < -asteroid:
                    # Right-moving asteroid destroyed, continue checking
                    stack.pop()
                    continue
                elif stack[-1] == -asteroid:
                    # Both destroyed
                    stack.pop()
                    break
                else:
                    # Left-moving asteroid destroyed
                    break
            else:
                # Only append if we didn't break (asteroid survived)
                stack.append(asteroid)
        
        return stack