class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
    int max_count = 0, count = 0;
    for (auto num : nums) {
        if (num == 1) {
            count++;
            max_count = std::max(max_count, count);
        } else {
            count = 0;
        }
    }
    return max_count;
}
};