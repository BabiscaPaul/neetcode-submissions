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
    void dfs(TreeNode *root, std::vector<std::string>& res) {
        if (!root) {
            res.push_back("null");
            return;
        }
        dfs(root->left ,res);
        dfs(root->right, res);
        res.push_back(std::to_string(root->val));
    }
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        std::vector<std::string> r1, r2;
        dfs(p, r1);
        dfs(q, r2);
        return r1 == r2;
    }
};
