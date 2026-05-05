class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto first = std::lower_bound(nums.begin(), nums.end(), target);
        auto last = std::upper_bound(nums.begin(), nums.end(), target);
        if (first == nums.end() || *first != target) return {-1, -1};
        return {(first - nums.begin()), (last - nums.begin() - 1)};
    }
};