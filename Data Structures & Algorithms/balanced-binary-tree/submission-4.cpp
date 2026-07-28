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
    std::pair<bool, int> dfs(TreeNode* root) {
        if (!root) return {true, 0};

        auto left = dfs(root->left);
        auto right = dfs(root->right);

        int diff = std::abs(left.second - right.second);\
        bool is_balanced = diff <= 1 && (left.first && right.first);

        return {is_balanced, std::max(left.second, right.second) + 1};
    }
public:
    bool isBalanced(TreeNode* root) {
        return dfs(root).first;
    }
};
