#include <vector>
#include <algorithm>

class Solution {
public:
    int minSubArrayLen(int target, std::vector<int>& nums) {
        int runningSum = 0, minWindow = static_cast<int>(nums.size());
        int l = 0;

        bool found = false;

        for (int r = 0; r < static_cast<int>(nums.size()); ++r) {
            runningSum += nums[r];

            while (runningSum >= target) {
                found = true;
                minWindow = std::min(minWindow, r - l + 1);
                runningSum -= nums[l];
                ++l;
            }
        }

        if (found) return minWindow;
        return 0;
    }
};