/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    void reorderList(ListNode* head) {
        std::vector<ListNode*> node_ptrs;
        ListNode* curr = head;

        while (curr) {
            node_ptrs.push_back(curr);
            curr = curr->next;
        }

        for (auto node: node_ptrs) {
            node->next = nullptr;
        }

        size_t i = 0, j = node_ptrs.size() - 1;

        while (i < j) {
            node_ptrs[i]->next = node_ptrs[j];

            ++i;
            
            if (node_ptrs.size() % 2 == 0 && i < node_ptrs.size() / 2 || node_ptrs.size() % 2 == 1 && i <= node_ptrs.size() / 2)
                node_ptrs[j]->next = node_ptrs[i];

            --j;
        }
    }
};
