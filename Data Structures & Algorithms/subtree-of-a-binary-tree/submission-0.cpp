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
    bool is_same_tree(TreeNode* first_root, TreeNode* second_root) {
        if (!first_root && !second_root) return true;
        if (!first_root || !second_root) return false;
        if (first_root->val != second_root->val) return false;

        auto left = is_same_tree(first_root->left, second_root->left);
        auto right = is_same_tree(first_root->right, second_root->right);

        return left && right;
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root) return false;
        auto res = is_same_tree(root, subRoot);
        if (res) return true;

        auto left = isSubtree(root->left, subRoot);
        auto right = isSubtree(root->right, subRoot);

        return left || right;
    }
};