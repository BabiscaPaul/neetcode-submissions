#include <cstddef>
#include <vector> 
using std::vector;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        std::vector<int> pre_prod(nums.size(), 1), post_prod(nums.size(), 1);
        std::vector<int> result {};
        
        int curr_prod = 1;

        for (std::size_t i = 0; i < nums.size(); ++i) {
            pre_prod[i] = curr_prod;
            curr_prod *= nums[i];
        }

        curr_prod = 1;

        for (int i = static_cast<int>(nums.size() - 1); i >= 0; --i) {
            post_prod[i] = curr_prod;
            curr_prod *= nums[i];
        }

        for (std::size_t i = 0; i < nums.size(); ++i)
            result.push_back(pre_prod[i] * post_prod[i]);

        return result;
    }
};
