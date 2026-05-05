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
    int dfs(TreeNode* root, int &res) {
        if (root == nullptr) return 0;

        int left_diam = dfs(root->left, res);
        int right_diam = dfs(root->right, res);

        res = std::max(res, left_diam + right_diam);

        return std::max(left_diam, right_diam) + 1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diam{0};
        dfs(root, diam);
        return diam;
    }
};