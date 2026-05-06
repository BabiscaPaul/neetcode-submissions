/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
    private:    
        std::pair<int, int> dfs(TreeNode* root) {
            if (!root) return {0, 0};

            auto [robbed_left_child, didntrob_left_child] = dfs(root->left);
            auto [robbed_right_child, didnt_rob_right_child] = dfs(root->right);

            auto not_rob_curr = std::max(robbed_left_child, didntrob_left_child) + std::max(robbed_right_child, didnt_rob_right_child);

            return {didntrob_left_child + didnt_rob_right_child + root->val, not_rob_curr};
        }

    public:
        int rob(TreeNode* root) {
            auto res = dfs(root);
            return std::max(res.first, res.second);
        }
};