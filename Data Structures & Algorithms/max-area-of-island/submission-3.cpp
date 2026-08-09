#include <algorithm>
#include <vector>
using std::vector;

class Solution {
private:
    constexpr static int dirs[4][2] {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    int dfs(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) return 0;
        if (grid[i][j] == 0) return 0;

        grid[i][j] = 0; // visit

        int curr_area = 0;

        for (const auto [dr, dc]: dirs) {
            curr_area += dfs(grid, i + dr, j + dc);
        }

        return ++curr_area;
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maximum_area = 0;
        int ROWS = grid.size();
        int COLS = grid[0].size();

        for (int i = 0; i < ROWS; ++i)
            for (int j = 0; j < COLS; ++j)
                if (grid[i][j] == 1) 
                    maximum_area = std::max(dfs(grid, i, j), maximum_area);

        return maximum_area;
    }
};
