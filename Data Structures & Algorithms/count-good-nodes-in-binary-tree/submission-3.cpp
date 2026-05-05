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
        void dfs(std::stack<int>& mono_stack, TreeNode* root, int& count) {
            if (!root) return;
            
            if (mono_stack.empty() || root->val >= mono_stack.top()) {
                mono_stack.push(root->val);
                count++;
            }

            dfs(mono_stack, root->left, count);
            dfs(mono_stack, root->right, count);

            if (!mono_stack.empty() && root->val == mono_stack.top()) mono_stack.pop();
        }

    public:
        int goodNodes(TreeNode* root) {
            std::stack<int> mono_stack{};
            int count = 0;
            dfs(mono_stack, root, count);
            return count;
        }
};