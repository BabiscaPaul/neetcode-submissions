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
    bool hasCycle(ListNode* head) {
        ListNode* curr = head;
        std::unordered_set<ListNode*> seen_so_far;

        while (curr) {
            if (seen_so_far.contains(curr))
                return true;
            seen_so_far.insert(curr);
            curr = curr->next;
        }

        return false;
    }
};
