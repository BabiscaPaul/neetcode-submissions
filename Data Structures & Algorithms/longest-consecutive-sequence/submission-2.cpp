
/*
    nums = [2,20,4,10,3,4,5]
                          i
    seen = {2, 20, 4}

    ---------------------------------------------->

    
    cnt = 0
*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_set<int> unique_nums(nums.begin(), nums.end());
        std::vector<int> start;

        for (int num: unique_nums) {
            if (!unique_nums.contains(num - 1))
                start.push_back(num);
        }

        int max = 0;
        for (int num: start) {
            int curr = num, count = 0;
            while (unique_nums.contains(curr)) {
                ++count;
                ++curr;
            }
            max = std::max(count, max);
        }

        return max;
    }
};
