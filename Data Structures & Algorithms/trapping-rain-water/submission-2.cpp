#include <algorithm>
#include <ranges>
#include <vector>

class Solution {
public:
    int trap(std::vector<int>& height) {
        std::vector<int> max_left;
        std::vector<int> max_right(height.size(), 0);

        int curr_max = 0;
        for (auto n: height) {
            max_left.push_back(curr_max);
            curr_max = std::max(curr_max, n);
        }
        curr_max = 0;
        for (int i = height.size() - 1; i >= 0; i--) {
            max_right[i] = curr_max;
            curr_max = std::max(curr_max, height[i]);
        }

        int result = 0;

        for (int i = 0; i < height.size(); ++i)
            result += std::max(0, std::min(max_left[i], max_right[i]) - height[i]);

        return result;
    }
};