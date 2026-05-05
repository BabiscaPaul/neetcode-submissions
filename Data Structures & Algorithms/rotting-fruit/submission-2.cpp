class Solution {
    using Queue = std::queue<std::pair<int, int>>;

private:
    static constexpr int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    static constexpr int EMPTY = 0, FRESH = 1, ROTTEN = 2;
    int ROWS = 0, COLS = 0;

    int bfs(vector<vector<int>>& grid, Queue& queue) {
        int minutes = 0;

        while (!queue.empty()) {
            int currLen = queue.size();

            for (int i = 0; i < currLen; ++i) {
                
                auto [currRow, currCol] = queue.front();
                queue.pop();

                for (auto [dr, dc]: dirs) {
                    auto nr = dr + currRow, nc = dc + currCol;
                    if (nr >= 0 && nr < ROWS && nc >= 0 && nc < COLS && grid[nr][nc] == FRESH) {
                        grid[nr][nc] = ROTTEN;
                        queue.push({nr, nc});
                    }
                }

            }
            ++minutes;
        }

        return std::max(0, minutes - 1);
    }

public:
    int orangesRotting(vector<vector<int>>& grid) {
        ROWS = static_cast<int>(grid.size());
        COLS = static_cast<int>(grid[0].size());
        Queue queue;

        for (int i = 0; i < ROWS; ++i) {
            for (int j = 0; j < COLS; ++j) {
                if (grid[i][j] == ROTTEN) {
                    queue.push({i, j});
                }
            }
        }
        
        int minutes = bfs(grid, queue);

        for (int i = 0; i < ROWS; ++i) {
            for (int j = 0; j < COLS; ++j) {
                if (grid[i][j] == FRESH) return -1;
            }
        }

        return minutes;
    }
};
