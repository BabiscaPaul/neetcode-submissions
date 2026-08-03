class Solution {
private:
    void dfs(const vector<int>& nums, vector<vector<int>>& result, vector<int>& partial_res, size_t start=0) {
        result.push_back(partial_res);

        for (size_t i = start; i < nums.size(); ++i) {
            partial_res.push_back(nums[i]);
            dfs(nums, result, partial_res, i + 1);
            partial_res.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        std::vector<int> partial;
        std::vector<vector<int>> res;
        dfs(nums, res, partial);
        return res;
    }
};
