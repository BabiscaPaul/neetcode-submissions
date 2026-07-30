/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *   
$0  TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */


class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        std::queue<TreeNode*> queue;
        std::vector<vector<int>> res;
        queue.push(root);
        
        while (queue.size() > 0) {
            size_t len = queue.size();
            std::vector<int> curr_level;
            
            for (size_t i = 0; i < len; ++i) {
                auto front = queue.front();
                curr_level.push_back(front->val);
                if (front->left) queue.push(front->left);
                if (front->right) queue.push(front->right);
                queue.pop();
            }

            res.push_back(curr_level);
        }

        return res;
    }
};
