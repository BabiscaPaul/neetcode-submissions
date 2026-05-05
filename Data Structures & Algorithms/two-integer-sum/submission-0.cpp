class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> needed; // {num -> index}

        for (int i = 0; i < nums.size(); ++i) {
            const auto complement = target - nums[i];
            if (needed.contains(complement)) 
                return {needed[complement], i};
            needed.insert({nums[i], i});
        }

        return {};
    }
};
