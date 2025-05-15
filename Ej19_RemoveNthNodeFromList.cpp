#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        ListNode* nodoAEliminar = head;

        if(temp->next == nullptr) return 0;

        for(int i=0; i<n; i++){
            temp = temp->next;
        }

        if(temp == nullptr){
            head = head->next;
            return head;
        }

        while(temp->next != nullptr){
            temp = temp->next;
            nodoAEliminar = nodoAEliminar->next;
        }

        nodoAEliminar->next = nodoAEliminar->next->next;

        return head;

    }
};


int main(){

    ListNode a2(2);
    ListNode a1(1, &a2);

    ListNode b4(9);
    ListNode b3(4, &b4);
    ListNode b2(6, &b3);
    ListNode b1(5, &b2);

    Solution sol;
    ListNode* rpta = sol.removeNthFromEnd(&a1, 2);

    while(rpta->next != nullptr){
        cout<<rpta->val<<" -> ";
        rpta = rpta->next;
    }
    cout<<rpta->val;


    return 0;
}