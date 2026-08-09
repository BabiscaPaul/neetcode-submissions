#include <cstddef>
#include <vector>
using std::vector;

class Solution {
private:
    constexpr static int dirs[4][2]{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    void dfs(vector<vector<char>>& grid, std::size_t i, std::size_t j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) return;
        if (grid[i][j] == '0') return;

        grid[i][j] = '0'; // visit

        for (const auto [dr, dc]: dirs) {
            dfs(grid, i + dr, j + dc);
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int total_islands = 0;

        for (std::size_t i = 0; i < grid.size(); ++i) {
            for (std::size_t j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j);
                    ++total_islands;
                }
            }
        }

        return total_islands;
    }
};
