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
    struct RobState {
        int rob;
        int skip;
    };

    RobState dfs(const TreeNode* node) {
        if (node == nullptr) {
            return {0, 0};
        }

        const auto left = dfs(node->left);
        const auto right = dfs(node->right);

        const int rob = node->val + left.skip + right.skip;
        const int skip = std::max(left.rob, left.skip) + std::max(right.rob, right.skip);

        return {rob, skip};
    }

public:
    int rob(TreeNode* root) {
        const auto result = dfs(root);
        return std::max(result.rob, result.skip);
    }
};