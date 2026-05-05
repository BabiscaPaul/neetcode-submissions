#include <vector>
using std::vector;

class Solution {
    private:
        void setRowAndCol(vector<vector<int>>& matrix, int row, int col) {
            int ROWS = matrix.size(), COLS = matrix[0].size();

            for (int i = 0; i < ROWS; ++i)
                matrix[i][col] = 0;

            for (int j = 0; j < COLS; ++j)
                matrix[row][j] = 0;
        }

    public:
        void setZeroes(vector<vector<int>>& matrix) {
            vector<std::pair<int, int>> zero_positions;
            int ROWS = matrix.size(), COLS = matrix[0].size();

            // first collect all the zeros
            for (int i = 0; i < ROWS; ++i) 
                for (int j = 0; j < COLS; ++j) 
                    if (matrix[i][j] == 0) zero_positions.emplace_back(i, j);

            for (auto [i, j]: zero_positions)
                setRowAndCol(matrix, i, j);
        }
};
