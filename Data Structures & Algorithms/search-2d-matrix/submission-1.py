class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        ROWS, COLS = len(matrix), len(matrix[0])

        def bs(row: List[int]) -> bool:
            l, r = 0, len(row) - 1
            while l <= r:
                mid = (l + r) // 2
                if row[mid] == target: return True 
                else:
                    if target > row[mid]: l = mid + 1
                    else: r = mid - 1
            return False

        l, r = 0, ROWS - 1

        while l <= r:
            mid = (l + r) // 2
            if matrix[mid][0] <= target <= matrix[mid][-1]:
                return bs(matrix[mid])
            else:
                if target > matrix[mid][-1]:
                    l = mid + 1
                else: r = mid - 1
        return False