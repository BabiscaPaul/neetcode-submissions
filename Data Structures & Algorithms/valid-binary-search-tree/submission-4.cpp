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
    void dfs(TreeNode* root, std::vector<int>& vals) {
        if (!root) return;

        dfs(root->left, vals);
        vals.push_back(root->val);
        dfs(root->right, vals);
    }
public:
    bool isValidBST(TreeNode* root) {
        std::vector<int> values;
        dfs(root, values);
        for (size_t i = 0; i < values.size(); ++i) {
            size_t j = i + 1;
            if (j < values.size() && values[i] >= values[j])
                return false;
        }

        return true;
    }
};
