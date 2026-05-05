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
        void dfs(TreeNode* root, TreeNode* newNode) {
            if (!root->left && newNode->val < root->val) {
                root->left = newNode;
                return;
            } else if (!root->right && newNode->val > root->val) {
                root->right = newNode;
                return;
            } 

            if (newNode->val < root->val) dfs(root->left, newNode);
            else dfs(root->right, newNode);
        }
        
    public:
        TreeNode* insertIntoBST(TreeNode* root, int val) {
            TreeNode* newNode = new TreeNode{val};
            if (!root) return newNode;

            dfs(root, newNode);
            return root;
        }
};