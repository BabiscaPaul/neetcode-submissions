class Solution {
    int ROWS, COLS;

    static constexpr int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    void dfs(int i, int j, vector<vector<bool>>& visited, const vector<vector<char>>& board) {
        if (i < 0 || i >= ROWS || j < 0 || j >= COLS || visited[i][j] || board[i][j] == 'X')
            return;

        visited[i][j] = true;

        for (auto [dr, dc]: dirs) {
            auto nr = i + dr, nc = j + dc;
            dfs(nr, nc, visited, board);
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        ROWS = static_cast<int>(board.size());
        COLS = static_cast<int>(board[0].size());

        vector<vector<bool>> visited(ROWS, vector<bool>(COLS, false));

        // dfs on borders if cell == O
        for (int c = 0; c < COLS; ++c) {
            if (board[0][c] == 'O') dfs(0, c, visited, board);
            if (board[ROWS - 1][c] == 'O') dfs(ROWS - 1, c, visited, board);
        }
        for (int r = 0; r < ROWS; ++r) {
            if (board[r][0] == 'O') dfs(r, 0, visited, board);
            if (board[r][COLS - 1] == 'O') dfs(r, COLS - 1, visited, board);
        }


        for (int i = 0; i < ROWS; ++i) {
            for (int j = 0; j < COLS; ++j) {
                if (!visited[i][j] && board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
    }
};