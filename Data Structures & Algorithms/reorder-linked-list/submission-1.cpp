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
private:
    ListNode* reverse(ListNode* head) {
        if (head == nullptr) return nullptr;
        
        ListNode *prev = nullptr, *curr = head;

        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
public:
    void reorderList(ListNode* head) {
        if (!head || head->next == nullptr) return;

        ListNode *slow = head, *fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* curr = head;

        while (curr && curr->next != slow)
            curr = curr->next;
        
        curr->next = nullptr; // split the list

        ListNode *first = head, *second = reverse(slow);

        while (first && second) {
            ListNode *tmp1 = first->next, *tmp2 = second->next;

            first->next = second;
            if (tmp1)
                second->next = tmp1;

            first = tmp1;
            second = tmp2;
        }
    }
};