class Solution {
    using Grid = vector<vector<int>>;
    using gridSet = vector<vector<bool>>;
    int ROWS = 0, COLS = 0;

    constexpr static int dirs[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

    void dfs(int i, int j, gridSet& grid, const Grid& heights) {
        if (i < 0 || i >= ROWS || j < 0 || j >= COLS || grid[i][j])
            return;

        grid[i][j] = true; // mark as visited

        for (auto [dr, dc]: dirs) {
            auto nr = i + dr, nc = j + dc;
            if (nr >= 0 && nr < ROWS && nc >= 0 && nc < COLS && !grid[nr][nc] && heights[nr][nc] >= heights[i][j])
                dfs(nr, nc, grid, heights);
        }
    }

public:
    vector<vector<int>> pacificAtlantic(Grid& heights) {
        ROWS = static_cast<int>(heights.size());
        COLS = static_cast<int>(heights[0].size());

        gridSet pacific(ROWS, vector<bool>(COLS, false));
        gridSet atlantic(ROWS, vector<bool>(COLS, false));

        vector<vector<int>> result;

        // pacific 
        for (int c = 0; c < COLS; ++c) {
            dfs(0, c, pacific, heights);
        }

        for (int i = 0; i < ROWS; ++i) {
            dfs(i, 0, pacific, heights);
        }

        // atlantic
        for (int c = 0; c < COLS; ++c) {
            dfs(ROWS - 1, c, atlantic, heights);
        }

        for (int i = 0; i < ROWS; ++i) {
            dfs(i, COLS - 1, atlantic, heights);
        }

        // now get only the indeces that are in both sets 
        for (int i = 0; i < ROWS; ++i) {
            for (int j = 0; j < COLS; ++j) {
                if (pacific[i][j] && atlantic[i][j]) {
                    result.push_back({i, j});
                }
            }
        }

        return result;
    }
};
