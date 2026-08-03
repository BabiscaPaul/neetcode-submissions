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
    bool dfs(TreeNode* root, int min, int max) {
        if (!root) return true;
        if (! (root->val > min && root->val < max)) return false;

        bool left_subtree = dfs(root->left, min, root->val);
        bool right_subtree = dfs(root->right, root->val, max);

        return left_subtree && right_subtree;
    }
public:
    bool isValidBST(TreeNode* root) {
        return dfs(root, INT_MIN, INT_MAX);
    }
};

