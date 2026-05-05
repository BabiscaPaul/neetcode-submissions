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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *tail1 = list1, *tail2 = list2;
        ListNode dummy{0, nullptr};
        ListNode* curr = &dummy;

        while(tail1 && tail2) {
            if (tail1->val < tail2->val) {
                curr->next = tail1;
                tail1 = tail1->next;
            } else {
                curr->next = tail2;
                tail2 = tail2->next;
            }
            curr = curr->next;
        }

        if (tail1) {
            curr->next = tail1;
        } else if (tail2) {
            curr->next = tail2;
        }

        return dummy.next;
    }
};
