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

    std::pair<int, bool> dfs(TreeNode* root) {
    if (root == nullptr) {
        return {0, true};
    }

    auto left = dfs(root->left);
    auto right = dfs(root->right);

    int height = std::max(left.first, right.first) + 1;

    bool children_balanced = left.second && right.second;
    bool current_balanced = std::abs(left.first - right.first) <= 1;

    return {height, children_balanced && current_balanced};
}

    
public:
    bool isBalanced(TreeNode* root) {
        return dfs(root).second;
    }
};
