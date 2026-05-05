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
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};

        std::queue<TreeNode *> q{};
        q.push(root);

        std::vector<int> res{};


        while (!q.empty()) {
            const int curr_level_len = static_cast<int>(q.size());
            const TreeNode* rightmost = nullptr;

            for (auto i = 0; i < curr_level_len; ++i) {
                const TreeNode* curr_node = q.front();
                rightmost = curr_node;

                if (curr_node->left) q.push(curr_node->left);
                if (curr_node->right) q.push(curr_node->right);
                q.pop();
            }

            res.push_back(rightmost->val);
        }

        return res;
    }
};
