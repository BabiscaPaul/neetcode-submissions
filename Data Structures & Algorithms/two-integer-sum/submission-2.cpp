#include <unordered_map>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> map;

        for (int i = 0; i < nums.size(); ++i) {
            const int num = nums[i];
            int needed = target - num;

            auto it = map.find(needed);

            if (it != map.end())
                return { it->second, i };

            map[num] = i;
        }

        return {};
    }
};
