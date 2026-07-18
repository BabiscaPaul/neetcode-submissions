/*
    nums = [2, 20, 4, 10, 3, 4, 5]
    --- sort --->
    nums = [2, 3, 4, 4, 5, 10, 20]
            i
    unique_nums = [2, 3, 4, 5, 10, 20]
    
    len = 0

*/

class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        std::unordered_set<int> seen;
        std::vector<int> unique_nums;
        
        for (int num: nums) {
            if (!seen.contains(num))
                unique_nums.push_back(num);
            seen.insert(num);
        }

        int count = 0, max_len = 0;
        for (size_t i = 0; i < unique_nums.size(); ++i) {
            if (i > 0 && unique_nums[i] != unique_nums[i - 1] + 1)
                count = 0;
                
            count++;
            max_len = std::max(max_len, count);
        }

        return max_len;
    }
};
