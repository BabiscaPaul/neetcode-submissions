#include <unordered_map>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> map;

        for (int i = 0; i < nums.size(); ++i) {
            const int num = nums[i];
            int needed = target - num;
            
            if (map.contains(needed)) 
                return {map[needed], i};

            map[num] = i;
        }

        return {};
    }
};
