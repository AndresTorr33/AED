#include <iostream>

using namespace std;

// 100% ASÍ. LOS CODIGOS EN COMENTARIOS NO SON NECESARIOS

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

//        if(head->next->next == nullptr){
//            if(head->val == (head->next)->val){
//                head->next = nullptr;
//            }
//            return head;
//        }
        ListNode* curr = head;

//        ListNode *temp = head; // Ahorita cola está en posición de head
//        while (temp->next != nullptr) {
//            cout << temp->val << " ";
//            temp = temp->next;
//        }
//        cout << temp->val;
//        cout << endl;

        curr = curr->next;

        while(true){
            if(previo->val == curr->val){
                numsIguales = true;
            }
            else{
                if(numsIguales){
                    previo->next = curr;
                    if(previo->val == curr->val){
                        numsIguales = true;
                    }
                    else numsIguales = false;
                }else{
                    previo = previo->next;
                    if(previo->val == curr->val){
                        numsIguales = true;
                    }
                }
            }
            if(curr->next == nullptr) break;
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
    ListNode nodo7 (3);
    ListNode nodo6 (3, &nodo7);
    ListNode nodo5(2, &nodo6);
    ListNode nodo4(2, &nodo5);
    ListNode nodo3(1, &nodo4);
    ListNode nodo2(1, &nodo3);
    ListNode nodo1(1, &nodo2);

    Solution sol;
    ListNode* solucion = sol.deleteDuplicates(&nodo1);

    //Imprimir
    while(true){
        cout<<solucion->val<<" ";
        if(solucion->next == nullptr) break;
        solucion = solucion->next;
    }

    return 0;
}
