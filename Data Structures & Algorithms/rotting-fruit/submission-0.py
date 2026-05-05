from typing import List
from collections import deque

class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        visited = set()
        queue = deque()
        directions = [[0, 1], [0, -1], [1, 0], [-1, 0]]
        ROWS, COLS = len(grid), len(grid[0])
        total_minutes = 0
        
        for i in range(ROWS):
            for j in range(COLS):
                if grid[i][j] == 2: 
                    queue.append([i, j, 0])
                    visited.add((i, j))
        
        while queue:
            row, col, minutes = queue.popleft()
            total_minutes = minutes
            
            for dr, dc in directions:
                next_row, next_col = row + dr, col + dc
                if (
                    0 <= next_row < ROWS and 
                    0 <= next_col < COLS and 
                    (next_row, next_col) not in visited and 
                    grid[next_row][next_col] == 1
                ):
                    visited.add((next_row, next_col))
                    queue.append([next_row, next_col, minutes + 1])
        
        for i in range(ROWS):
            for j in range(COLS):
                if (i, j) not in visited and grid[i][j] == 1: return -1
        
        return total_minutes