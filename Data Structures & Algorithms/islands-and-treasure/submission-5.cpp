#include <cstddef>
#include <utility>
#include <vector>
#include <queue>
using std::vector;

class Solution {
    private:
        constexpr static int LAND = 2147483647;
        constexpr static int TREASURE = 0;
        constexpr static int WATER = -1;

        constexpr static int dirs[4][2] {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    public:
        void islandsAndTreasure(vector<vector<int>>& grid) {
            std::queue<std::pair<int, int>> queue;
            std::size_t ROWS = grid.size(), COLS = grid[0].size();

            for (std::size_t i = 0; i < ROWS; ++i) {
                for (std::size_t j = 0; j < COLS; ++j) {
                    if (grid[i][j] == 0)
                        queue.push({i, j});
                }
            }

            while (queue.size()) {
                std::size_t curr_size = queue.size();

                for (std::size_t i = 0; i < curr_size; ++i) {
                    const auto [curr_row, curr_col] = queue.front();
                    queue.pop();

                    for (const auto [dr, dc]: dirs) {
                        const auto next_row = curr_row + dr, next_col = curr_col + dc;
                        if (next_row >= 0 && next_row < ROWS && next_col >= 0 && next_col < COLS && grid[next_row][next_col] == LAND) {
                            grid[next_row][next_col] = grid[curr_row][curr_col] + 1;
                            queue.push({next_row, next_col});
                        }
                    }
                }
            }
        }
};
