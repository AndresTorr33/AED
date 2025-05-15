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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* previo = head;

        bool numsIguales = false;

        if(head == nullptr or head->next == nullptr) return head;

        if(head->next->next == nullptr){
            if(head == head->next){
                head->next = nullptr;
            }
            return head;
        }
        ListNode* curr = head;

//        ListNode *temp = head; // Ahorita cola está en posición de head
//        while (temp->next != nullptr) {
//            cout << temp->val << " ";
//            temp = temp->next;
//        }
//        cout << temp->val;
//        cout << endl;

        curr = curr->next;

        while(curr->next != nullptr){
            if(previo->val == curr->val){
                numsIguales = true;
            }
            else{
                if(numsIguales){
                    previo->next = curr;
                    numsIguales = false;
                }else{
                    previo = previo->next;
                }
            }
            curr = curr->next;
        }

        if(previo->val == curr->val){
            curr = nullptr;
        }
        previo->next = curr;


//        temp = head; // Ahorita cola está en posición de head
//        while (temp->next != nullptr) {
//                cout << temp->val << " ";
//                temp = temp->next;
//        }
//        cout << temp->val;
//        cout << endl;

        return head;
    }
};

int main(){
    ListNode nodo3(2);
    ListNode nodo2(2, &nodo3);
    ListNode nodo1(1, &nodo2);

    Solution sol;
    sol.deleteDuplicates(&nodo1)->val;

    return 0;
}
