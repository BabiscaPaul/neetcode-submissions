from typing import List

class Solution:
    def islandPerimeter(self, grid: List[List[int]]) -> int:
        ROWS, COLS = len(grid), len(grid[0])
        directions = [[0, 1], [0, -1], [1, 0], [-1, 0]]
        visited = set()
        
        def dfs(i: int, j: int) -> int:
            if not (0 <= i < ROWS) or not (0 <= j < COLS) or grid[i][j] == 0:
                return 1
            if (i, j) in visited: return 0
            
            visited.add((i, j))
            curr_perimeter = 0
            for dr, dc in directions:
                curr_perimeter += dfs(i + dr, j + dc)
            
            return curr_perimeter
        
        for i in range(ROWS):
            for j in range(COLS):
                if grid[i][j] == 1: return dfs(i, j)
        
        return 0