class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        std::vector<int> out;
        int prod = 1;
        for (size_t i = 0; i < nums.size(); ++i) {
            for (size_t j = 0; j < nums.size(); j++) {
                if (j != i)
                    prod *= nums[j];
            }
            out.push_back(prod);
            prod = 1;
        }
        return out;
    }
};
