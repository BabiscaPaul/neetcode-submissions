from typing import List
from collections import deque

class Solution:
    def islandsAndTreasure(self, grid: List[List[int]]) -> None:
        land, treasure = 2 ** 31 - 1, 0
        ROWS, COLS = len(grid), len(grid[0])
        queue = deque()
        directions = [[0, 1], [0, -1], [1, 0], [-1, 0]]
        
        for i in range(ROWS):
            for j in range(COLS):
                if grid[i][j] == treasure: 
                    queue.append((i, j, 0))
        
        while queue:
            row, col, dist = queue.popleft()
            
            for dr, dc in directions:
                next_row, next_col = row + dr, col + dc
                
                if (0 <= next_row < ROWS and 
                    0 <= next_col < COLS and 
                    grid[next_row][next_col] == land):
                    
                    grid[next_row][next_col] = dist + 1
                    queue.append((next_row, next_col, dist + 1))