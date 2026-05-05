from typing import List
from collections import deque

class Solution:
    def islandsAndTreasure(self, grid: List[List[int]]) -> None:
        land, treasure = 2 ** 31 - 1, 0
        ROWS, COLS = len(grid), len(grid[0])
        visited = set()
        queue = deque()
        directions = [[0, 1], [0, -1], [1, 0], [-1, 0]]
        
        for i in range(ROWS):
            for j in range(COLS):
                if grid[i][j] == treasure: 
                    queue.append([i, j, 0])
        
        while queue:
            queue_len = len(queue)
            
            for _ in range(queue_len):
                row, col, dist = queue.popleft()
                visited.add((row, col))
                
                for dr, dc in directions:
                    next_row, next_col = row + dr, col + dc
                    
                    if (0 <= next_row < ROWS) and (0 <= next_col < COLS) and grid[next_row][next_col] == land and (next_row, next_col) not in visited:
                        grid[next_row][next_col] = dist + 1
                        queue.append([next_row, next_col, dist + 1])