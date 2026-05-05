from typing import List

class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        max_area = 0
        visited = set()
        ROWS, COLS = len(grid), len(grid[0])
        dirs = [[0, 1], [0, -1], [1, 0], [-1, 0]]
        
        def dfs(i: int, j: int) -> int:
            if (i, j) in visited or not (0 <= i < ROWS) or not (0 <= j < COLS) or grid[i][j] == 0:
                return 0
            
            visited.add((i, j))
            area = 1
            for dr, dc in dirs:
                area += dfs(i + dr, j + dc)
            return area 
        
        for i in range(ROWS):
            for j in range(COLS):
                if (i, j) not in visited and grid[i][j] == 1: 
                    max_area = max(dfs(i, j), max_area)
        
        return max_area