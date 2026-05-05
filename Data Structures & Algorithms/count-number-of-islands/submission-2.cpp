class Solution {
public:
    std::vector<std::pair<int, int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

    void dfs(vector<vector<char>>& grid, int i, int j) {
        if (!(i >= 0 && i < grid.size()) || !(j >= 0 && j < grid[0].size()) || grid[i][j] == '0')
            return;
        
        grid[i][j] = '0'; // mark as visited;

        for (auto [dr, dc]: dirs) {
            dfs(grid, i + dr, j + dc);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int ROWS = grid.size(), COLS = grid[0].size(), count = 0;

        for (int i = 0; i < ROWS; ++i) {
            for (int j = 0; j < COLS; ++j) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j);
                    ++count;
                }
            }
        }

        return count;
    }
};
