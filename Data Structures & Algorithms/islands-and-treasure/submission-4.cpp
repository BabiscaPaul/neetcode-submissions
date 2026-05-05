class Solution {

    using Queue = std::queue<std::pair<int, int>>;

private:
    int ROWS = 0, COLS = 0;
    static constexpr int WATER = -1, TREASURE = 0, LAND = 2147483647;
    static constexpr int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    void bfs(vector<vector<int>>& grid, Queue queue) {
        while (!queue.empty()) {
            int currLen = static_cast<int>(queue.size());

            auto [row, col] = queue.front();
            queue.pop();

            for (auto [dr, dc]: dirs) {
                auto nr = dr + row, nc = dc + col;
                if (nr >= 0 && nr < ROWS && nc >= 0 && nc < COLS && grid[nr][nc] == LAND) {
                    queue.push({nr, nc});
                    grid[nr][nc] = grid[row][col] + 1;
                }
            }
        }
    }

public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        Queue queue;
        ROWS = static_cast<int>(grid.size());
        COLS = static_cast<int>(grid[0].size());

        for (int i = 0; i < ROWS; ++i) {
            for (int j = 0; j < COLS; ++j) {
                if (grid[i][j] == TREASURE)
                    queue.push({i, j});
            }
        }

        if (!queue.empty())
            bfs(grid, queue);
    }
};
