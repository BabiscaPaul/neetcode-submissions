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

#include <unordered_map>

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;
        
        std::unordered_map<Node*, Node*> hashmap; // mapping [old node] -> [new node]

        Node* curr = head;
        while (curr) {
            Node* newNode = new Node{curr->val};
            hashmap.insert({curr, newNode});
            curr = curr->next;
        }
        hashmap[nullptr] = nullptr;

        curr = head;
        Node *res = hashmap.at(curr);
        while (curr) {
            /*
                1. get new next 
                2. get new random
                3. do the wiring

            */
            Node *newNext = hashmap.at(curr->next), *newRandom = hashmap.at(curr->random);
            hashmap.at(curr)->next = newNext;
            hashmap.at(curr)->random = newRandom;
            curr = curr->next;
        }

        return res;
    }
};
