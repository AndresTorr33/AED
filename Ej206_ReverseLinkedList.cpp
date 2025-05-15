#include <iostream>

using namespace std;

//RESUELTO pero a mi manera. Igual sale 0ms, sacando los while de impresión.
// Más abajo hay solución más rápida

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// La class Solution de más abajo es más eficiente. Esta es mi primera versión
//class Solution {
//public:
//    ListNode* reverseList(ListNode* head) {
//        if(head == nullptr or head->next == nullptr){ // Si hay 0 o 1 valor
//            return head;
//        }
//        else if(head->next->next == nullptr){ // Si hay 2 valores
//            ListNode* temp = head;
//            head = head->next;
//            head->next = temp;
//            temp->next = nullptr;
//            return head;
//        }
//        else { // Si hay 3 o más valores
//            ListNode *cola = head;
//            ListNode *temp2 = head->next;
//            head = head->next->next;
//
//            ListNode *temp = cola; // Ahorita cola está en posición de head
//            while (temp->next != nullptr) {
//                cout << temp->val << " ";
//                temp = temp->next;
//            }
//            cout << temp->val;
//            cout << endl;
//
//            cola->next = nullptr; // La cola no apunta a nada
//            while(head->next != nullptr){
//                temp2->next = cola;
//                cola = temp2;
//                temp2 = head;
//                head = head->next;
//            }
//            temp2->next = cola;
//            cola = temp2;
//            head->next = temp2;
//
//            temp = head;
//            while(temp->next != nullptr){
//                cout<<temp->val<<" ";
//                temp = temp->next;
//            }
//            cout<<temp->val;
//
//            return head;
//        }
//    }
//};

// Resuelto en 0ms
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *previous = nullptr;
        ListNode *curr = head;

//        ListNode *temp = curr; // Ahorita cola está en posición de head
//        while (temp->next != nullptr) {
//                cout << temp->val << " ";
//                temp = temp->next;
//        }
//        cout << temp->val;
//        cout << endl;

        while(curr->next != nullptr){
            ListNode* nextNode = curr->next;
            curr->next = previous;
            previous = curr;
            curr = nextNode;
        }
        curr->next = previous;

//        temp = curr;
//        while (temp->next != nullptr) {
//            cout << temp->val << " ";
//            temp = temp->next;
//        }
//        cout << temp->val<<endl;
//        cout << endl;

        return curr;
    }
};

int main(){

    ListNode nodo3(3);
    ListNode nodo2(2, &nodo3);
    ListNode nodo1(1, &nodo2);

    Solution sol;
    cout<<sol.reverseList(&nodo1)->val;

    return 0;
}