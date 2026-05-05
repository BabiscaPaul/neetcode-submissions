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
        if (root == nullptr) return {0, true};
        auto left = dfs(root->left);
        auto right = dfs(root->right);
        
        bool is_balanced = left.second && right.second;
        int diff = abs(left.first - right.first);
        if (diff > 1) is_balanced = false;

        return {std::max(left.first, right.first) + 1, is_balanced};
    }
    
public:
    bool isBalanced(TreeNode* root) {
        return dfs(root).second;
    }
};
