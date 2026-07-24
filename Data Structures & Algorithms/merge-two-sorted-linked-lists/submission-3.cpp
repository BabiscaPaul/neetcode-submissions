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
        ListNode dummy{0, nullptr};
        ListNode* res = &dummy;
        ListNode *curr1 = list1, *curr2 = list2;

        while(curr1 && curr2) {
            if (curr1->val <= curr2->val) {
                res->next = curr1;
                curr1 = curr1->next;
            } else {
                res->next = curr2;
                curr2 = curr2->next;
            }

            res = res->next;
        }

        if (curr1) {
            res->next = curr1;
            res = res->next;
        }
        if(curr2)
            res->next = curr2;

        return dummy.next;
    }
};
