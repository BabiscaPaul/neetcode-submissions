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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if (root == nullptr)    
            return { };

        vector<vector<int>> res{ };
        map<int, vector<int>> levels{ };
        queue<std::pair<TreeNode*, int>> q;
        q.push({root, 0});

        while (!q.empty()) {
            auto front = q.front();
            if (front.first->left) q.push({front.first->left, front.second - 1});
            if (front.first->right) q.push({front.first->right, front.second + 1});

            q.pop();
            
            levels[front.second].push_back(front.first->val);
        }

        for (const auto& [key, val]: levels) {
            res.push_back(val);
        }

        return res;
    }
};