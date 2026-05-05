class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int c = 0;
        for (auto num: nums) {
            if (num == 1) c++;
        }
        if (c == 0) return 0;
        
        int max = 1, count = 1;
        
        if (nums.size() == 1) {
            return (nums[0] == 1) ? 1 : 0;
        }

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1] and nums[i] == 1) {
                count++;
                max = std::max(max, count);
            } 
            else {
                count = 1;
            }
        }

        return max;
    }
};