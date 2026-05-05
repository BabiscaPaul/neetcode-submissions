class Solution {
private:
    int ROWS, COLS;
    static constexpr int dirs[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

    int dfs(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || i >= ROWS || j < 0 || j >= COLS || grid[i][j] == 0)
            return 0;

        grid[i][j] = 0; // visit
        int curr_area = 1;

        for (auto [dr, dc]: dirs) {
            curr_area += dfs(grid, i + dr, j + dc);
        }

        return curr_area;
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        ROWS = (int)grid.size(), COLS = (int)grid[0].size();
        int max = 0;

        for (int i = 0; i < ROWS; ++i) {
            for (int j = 0; j < COLS; ++j) {
                if (grid[i][j] == 1)
                    max = std::max(max, dfs(grid, i, j));
            }
        }

        return max;
    }
};
