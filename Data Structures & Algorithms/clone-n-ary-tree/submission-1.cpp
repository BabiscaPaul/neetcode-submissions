/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
private:
    Node* dfs(Node* root) {
        if (root == nullptr) return nullptr;

        Node* copy = new Node{root->val};

        for (auto& child: root->children) {
            Node* node = dfs(child);
            copy->children.push_back(node);
        }

        return copy;
    }
public:
    Node* cloneTree(Node* root) {
        return dfs(root);
    }
};
