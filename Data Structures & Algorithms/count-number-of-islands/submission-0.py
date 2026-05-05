from typing import List

class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        visited = set()
        ROWS, COLS = len(grid), len(grid[0])
        island_count = 0
        directions = [[0, 1], [0, -1], [1, 0], [-1, 0]]
        
        def dfs(i: int, j: int) -> int:
            if (i, j) in visited or not (0 <= i < ROWS) or not (0 <= j < COLS) or grid[i][j] == '0': return 1
            
            visited.add((i, j))
            for dr, dc in directions:
                dfs(i + dr, j + dc)
            
            return 1
        
        for i in range(ROWS):
            for j in range(COLS):
                if grid[i][j] == '1' and (i, j) not in visited:
                    island_count += dfs(i, j)
                    
        return island_count