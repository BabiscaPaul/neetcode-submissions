class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prod = 1;
        std::vector<int> pre, post;
        
        for (int num: nums) {
            pre.push_back(prod);
            prod *= num;
        }

        prod = 1;

        for (auto it = nums.rbegin(); it != nums.rend(); ++it) {
            post.push_back(prod);
            prod *= *it;
        }

        std::reverse(post.begin(), post.end());

        std::vector<int> res;

        for (size_t i = 0; i < nums.size(); ++i) {
            res.push_back(pre[i] * post[i]);
        }

        return res;
    }
};