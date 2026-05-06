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
        void dfs(TreeNode* root, std::vector<int>& inorder_vals) {
            if (!root) return;
            dfs(root->left, inorder_vals);
            inorder_vals.push_back(root->val);
            dfs(root->right, inorder_vals);
        }
    public:
        bool isValidBST(TreeNode* root) {
            std::vector<int> inorder_vals{};
            dfs(root, inorder_vals);
            
            for (int i = 1; i < inorder_vals.size(); ++i) {
                if (inorder_vals[i] <= inorder_vals[i - 1])
                    return false;
            }

            return true;
    }
};
