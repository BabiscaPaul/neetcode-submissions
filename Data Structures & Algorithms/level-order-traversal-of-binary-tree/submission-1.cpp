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
        vector<vector<int>> levelOrder(TreeNode* root) {
            if (!root) return {};

            vector<vector<int>> res{};
            std::queue<TreeNode*> q{};
            q.push(root);

            while (!q.empty()) {
                vector<int> curr_row{};
                int level_size = q.size();

                for (int i = 0; i < level_size; ++i) {
                    TreeNode* curr = q.front();
                    q.pop();
                    curr_row.push_back(curr->val);

                    if (curr->left) q.push(curr->left);
                    if (curr->right) q.push(curr->right);
                }

                res.push_back(curr_row);
            }

            return res;
        }
};
