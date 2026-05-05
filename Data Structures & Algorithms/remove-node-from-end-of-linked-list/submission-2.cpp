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
    int getListSize(ListNode* head) const {
        int size = 0;
        while (head) {
            size++;
            head = head->next;
        }
        return size;
    }
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy{0, nullptr};
        dummy.next = head;
        ListNode* curr = &dummy;

        int k = getListSize(head) - n, count = -1;

        while (curr) {
            if (++count == k) {
                ListNode* toDelete = curr->next;
                if (toDelete)
                    curr->next = toDelete->next;
                free(toDelete);
                break;
            }
            curr = curr->next;
        }

        return dummy.next;
    }
};