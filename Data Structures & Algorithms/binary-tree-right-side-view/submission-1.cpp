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
            int curr_level_len = q.size();
            std::vector<int> curr_level;

            for (int i = 0; i < curr_level_len; ++i) {
                curr_level.push_back(q.front()->val);
                if (q.front()->left) q.push(q.front()->left);
                if (q.front()->right) q.push(q.front()->right);
                q.pop();
            }

            res.push_back(curr_level.back());
        }

        return res;
    }
};
