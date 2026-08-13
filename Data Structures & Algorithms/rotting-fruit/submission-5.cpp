#include <cstddef>
#include <queue>
#include <vector>
using std::vector;

struct QueueData {
    std::size_t row;
    std::size_t col;
    int minute;
};

using Queue = std::queue<QueueData>;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        Queue q{};
        std::size_t ROWS = grid.size(), COLS = grid[0].size();
        int result = 0;

        for (std::size_t i = 0; i < ROWS; ++i) 
            for (std::size_t j = 0; j < COLS; ++j) 
                if (grid[i][j] == ROTTEN_FRUIT)
                    q.push({i, j, 0});

        while (!q.empty()) {
            std::size_t curr_size = q.size();

            for (std::size_t i = 0; i < curr_size; ++i) {
                QueueData top = q.front();
                q.pop();
                
                for (const auto [dr, dc]: dirs) {
                    std::size_t next_row = top.row + dr, next_col = top.col + dc;

                    if (next_row < 0 || next_row >= ROWS || next_col < 0 || next_col >= COLS) continue;
                    if (grid[next_row][next_col] != FRESH_FRUIT) continue;

                    grid[next_row][next_col] = ROTTEN_FRUIT;
                    q.push({next_row, next_col, top.minute + 1});
                    result = top.minute + 1;
                }
            }
        }

        for (std::size_t i = 0; i < ROWS; ++i) 
            for (std::size_t j = 0; j < COLS; ++j) 
                if (grid[i][j] == FRESH_FRUIT)  
                    return -1;
        
        return result;
    }

private:
    static constexpr int EMPTY = 0, FRESH_FRUIT = 1, ROTTEN_FRUIT = 2;
    static constexpr int dirs[4][2] {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
};
