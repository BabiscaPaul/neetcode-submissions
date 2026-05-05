#include <vector> 
using std::vector;

class NumMatrix {
    vector<vector<int>> m_matrix;
    vector<vector<int>> m_sum_matrix;
    int ROWS, COLS;
public:
    NumMatrix(vector<vector<int>>& matrix) : m_matrix{matrix}, ROWS{static_cast<int>(m_matrix.size())}, COLS{static_cast<int>(m_matrix[0].size())} {
        m_sum_matrix.resize(matrix.size(), vector<int>(matrix[0].size(), 0));

        int i = 0, j = 0;

        for (i = 0; i < ROWS; ++i) {
            int curr_running_row_sum = 0;

            for (j = 0; j < COLS; ++j) {
                
                if (i > 0) {
                    m_sum_matrix[i][j] += m_sum_matrix[i - 1][j];
                }

                curr_running_row_sum += m_matrix[i][j];
                m_sum_matrix[i][j] += curr_running_row_sum;
            }
        }

    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int result = m_sum_matrix[row2][col2];
        if (row1 == 0 && col1 == 0) return result;

        if (col1 > 0) result -= m_sum_matrix[row2][col1 - 1];
        if (row1 > 0) result -= m_sum_matrix[row1 - 1][col2];
        if (row1 > 0 && col1 > 0) result += m_sum_matrix[row1 - 1][col1 - 1];

        return result;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */