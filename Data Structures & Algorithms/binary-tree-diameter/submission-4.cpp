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
    int dfs(TreeNode* root, int& diameter) {
        if (!root) return 0;

        int left = dfs(root->left, diameter);
        int right = dfs(root->right, diameter);

        int so_far = left + right;
        
        diameter = std::max(diameter, so_far);

        return std::max(left, right) + 1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int result{0};
        dfs(root, result);
        return result;
    }
};