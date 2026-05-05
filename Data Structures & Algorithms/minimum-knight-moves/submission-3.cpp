class Solution {
private:
    static constexpr int dirs[8][2] = {{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};

public:
    int minKnightMoves(int x, int y) {
        std::queue<std::tuple<int, int, int>> queue; // row, col, moves
        std::set<std::pair<int, int>> visited;

        queue.push({0, 0, 0});
        visited.insert({0, 0});

        while (!queue.empty()) {
            auto [row, col, numMoves] = queue.front();
            queue.pop();

            if (row == x && col == y) return numMoves;

            for (auto [dr, dc]: dirs) {
                auto nr = row + dr, nc = col + dc;
                if (!visited.count({nr, nc})) {
                    visited.insert({nr, nc});
                    queue.push({nr, nc, numMoves + 1});
                }
            }
        }

        return -1;
    }
};