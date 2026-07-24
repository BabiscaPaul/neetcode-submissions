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
    size_t get_list_size(ListNode* head) const {
        ListNode* curr = head;
        size_t len = 0;
        
        while (curr) {
            ++len;
            curr = curr->next;
        }

        return len;
    }
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy{};
        dummy.next = head;
        ListNode* curr = &dummy;

        size_t len = get_list_size(curr);
        size_t counter = 0;
        size_t k = len - n;

        while (counter < k && curr) {
            ++counter;
            
            if (counter == k) {
                auto to_del = curr->next;
                curr->next = curr->next->next;
                delete to_del;
                break;
            }

            curr = curr->next;
        }

        return dummy.next;
    }
};

