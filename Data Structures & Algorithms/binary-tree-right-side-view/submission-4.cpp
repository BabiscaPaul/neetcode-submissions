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
    std::vector<int> rightSideView(TreeNode* root) {
        std::deque<TreeNode *> queue{};
        if (root) queue.push_front(root);

        std::vector<int> res{};

        while (!queue.empty()) {
            res.push_back(queue.back()->val);
            std::size_t curr_size = queue.size();

            for (std::size_t i = 0; i < curr_size; ++i) {
                auto curr_node = queue.front();
                queue.pop_front();
                if (curr_node->left) queue.push_back(curr_node->left);
                if (curr_node->right) queue.push_back(curr_node->right);
            }
            
        }

        return res;
    }
};
