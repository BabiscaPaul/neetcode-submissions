#include <vector>
using std::vector;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix(nums.size(), 0);
        vector<int> postfix(nums.size(), 0);
        vector<int> result(nums.size(), 0);

        int prod = 1;
        for (int i = 0; i < nums.size(); ++i) {
            prefix[i] = prod;
            prod *= nums[i];
        }

        prod = 1;
        for (int i = nums.size() - 1; i >= 0; --i) {
            postfix[i] = prod;
            prod *= nums[i];
        }

        for (int i = 0; i < nums.size(); ++i) {
            result[i] = prefix[i] * postfix[i];
        }

        return result;
    }
};
