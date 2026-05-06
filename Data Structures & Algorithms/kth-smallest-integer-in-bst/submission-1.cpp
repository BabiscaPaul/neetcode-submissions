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
    public:
        int kthSmallest(TreeNode* root, int k) {
            // iterative stack approach 
            std::stack<TreeNode*> stack;
            TreeNode* curr = root;

            while (!stack.empty() || curr != nullptr) {
                
                while (curr) {
                    stack.push(curr);
                    curr = curr->left;
                }

                curr = stack.top();
                stack.pop();
                k--;

                if (k == 0) return curr->val;

                curr = curr->right;
            }

            return -1;
        }
};
