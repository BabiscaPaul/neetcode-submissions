class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_set<int> seen;
        for (const auto& num: nums) {
            if (seen.contains(num)) return true;
            seen.emplace(num);
        }
        return false;
    }
};