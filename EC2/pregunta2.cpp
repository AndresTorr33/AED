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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* begin = new ListNode(0);
        begin->next = head;

        ListNode* fast = begin;
        ListNode* slow = begin;

        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }

        while (fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        ListNode* target =  slow->next;
        if(slow->next){
            slow->next = slow->next->next;
        }

        delete target;
        return begin->next;
    }
};