#include <cstddef>
#include <queue>
#include <vector>
using std::vector;

// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;

//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr) return { };

        vector<int> result;
        std::queue<TreeNode*> queue;
        queue.push(root);

        while (queue.size() > 0uz) {
            size_t curr_len = queue.size();

            for (size_t i = 0; i < curr_len; ++i) {
                auto front = queue.front();
                queue.pop();
                if (front->left) queue.push(front->left);
                if (front->right) queue.push(front->right);

                if (i == curr_len - 1) result.push_back(front->val);
            }
        }

        return result;
    }
};
