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
        bool dfs(TreeNode* root, int targetSum, int runningSum) {
            if (!root) {
                return false;
            } 
            if (!root->left && !root->right) {
                runningSum += root->val;
                if (targetSum == runningSum)
                    return true;
                return false;
            }

            bool leftSubtree = dfs(root->left, targetSum, runningSum + root->val);
            bool rightSubtree = dfs(root->right, targetSum, runningSum + root->val);

            return leftSubtree || rightSubtree;
        }
    public:
        bool hasPathSum(TreeNode* root, int targetSum) {
            return dfs(root, targetSum, 0);
        }
};