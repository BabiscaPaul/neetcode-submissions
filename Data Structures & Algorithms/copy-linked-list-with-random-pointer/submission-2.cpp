/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        std::unordered_map<Node*, Node*> old_to_new_node_map{{nullptr, nullptr}};
        Node* curr = head;
        Node* result = head;
        
        while (curr) {
            Node* new_node = new Node{curr->val};
            old_to_new_node_map.insert({curr, new_node});
            curr = curr->next;
        }

        for (const auto& [old_node, new_node]: old_to_new_node_map) {
            if (old_node == nullptr) continue;
            Node* next_node = old_to_new_node_map.at(old_node->next);
            Node* random_node = old_to_new_node_map.at(old_node->random);
            new_node->next = next_node;
            new_node->random = random_node;
        }

        return old_to_new_node_map.at(result);
    }
};
