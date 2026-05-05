from collections import deque

class Solution:
    def shortestPathBinaryMatrix(self, grid: List[List[int]]) -> int:
        if grid[0][0] == 1: return -1

        ROWS = COLS = len(grid)
        queue = deque([[0, 0, 1]]) # row, col, length
        visited = set((0, 0))
        directions = [[0, 1], [0, -1], [1, 0], [-1, 0], [1, 1], [1, -1], [-1, 1], [-1, -1]]

        while queue:
            queue_len = len(queue)
            for _ in range(queue_len):
                row, col, curr_len = queue.popleft()
                if row == ROWS - 1 and col == COLS - 1: return curr_len
                for dr, dc in directions:
                    new_row, new_col = row + dr, col + dc
                    if (
                       0 <= new_row < ROWS and 
                       0 <= new_col < COLS and 
                       grid[new_row][new_col] == 0 and 
                       (new_row, new_col) not in visited
                    ):  
                        queue.append([new_row, new_col, curr_len + 1])
                        visited.add((new_row, new_col))
        
        return -1