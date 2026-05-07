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
    void dfs(TreeNode* root, double target, double& minimum, int& res) {
        if (root == nullptr) 
            return;

        if (std::abs(root->val - target) < minimum) {
            res = root->val;
            minimum = std::abs(root->val - target);
        }

        if (root->val > target) dfs(root->left, target, minimum, res);
        else dfs(root->right, target, minimum, res);
    }
public:
    int closestValue(TreeNode* root, double target) {
        int res{};
        double minimum{std::pow(10, 9)};
        dfs(root, target, minimum, res);
        return res;
    }
};