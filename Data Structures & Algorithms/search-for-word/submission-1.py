class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        from typing import List

class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        ROWS, COLS = len(board), len(board[0])
        visited = set()
        directions = [[0, 1], [0, -1], [1, 0], [-1, 0]]
        
        def dfs(i: int, j: int, index: int) -> bool:
            if (
                not 0 <= i < ROWS or 
                not 0 <= j < COLS or 
                (i, j) in visited or 
                word[index] != board[i][j]
            ):
                return False
            
            if index == len(word) - 1 and board[i][j] == word[-1]:
                return True 
            
            visited.add((i, j))
            
            found_word = False
            for dr, dc in directions:
                found_word = found_word or dfs(i + dr, j + dc, index + 1)
            
            visited.remove((i, j))
            return found_word
        
        for i in range(ROWS):
            for j in range(COLS):
                if board[i][j] == word[0]:
                    if dfs(i, j, 0): return True 
                    
        return False