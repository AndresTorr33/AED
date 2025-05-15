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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ptrA = l1;
        ListNode* ptrB = l2;
        ListNode* nuevaLista = new ListNode(0);
        ListNode* ptrNuevo = nuevaLista;
        int suma=0;
        int digito=0;
        int digitoPasado = 0;
        bool cerrarA=false, cerrarB=false, cerrado=false;

        while(ptrA->next != nullptr or ptrB->next != nullptr){
            if(ptrA->next == nullptr){
                suma += ptrB->val+digitoPasado;
                ptrB = ptrB->next;
                cerrarA=true;
            }
            else if(ptrB->next == nullptr){
                suma += ptrA->val+digitoPasado;
                ptrA = ptrA->next;
                cerrarB=true;
            }
            else{
                suma += ptrA->val+digitoPasado;
                suma += ptrB->val;

                ptrA = ptrA->next;
                ptrB = ptrB->next;
            }

            if(cerrarA and !cerrado){
                suma += ptrA->val;
                cerrado = true;
            }
            else if(cerrarB and !cerrado){
                suma += ptrB->val;
                cerrado = true;
            }

            if(suma>=10){
                digito = suma%10;
                digitoPasado = 1;
            }
            else{
                digito = suma;
                digitoPasado = 0;
            }

            ptrNuevo->val = digito;

            ListNode* sgte = new ListNode(0);

            ptrNuevo->next = sgte;

            ptrNuevo = ptrNuevo->next;

            suma=0;

        }

        if(cerrarA) suma = ptrB->val + digitoPasado;
        else if (cerrarB) suma = ptrA->val + digitoPasado;
        else{
            suma = ptrB->val + digitoPasado;
            suma += ptrA->val;
        }

        if(suma>=10){
            digito = suma%10;
            ptrNuevo->val = digito;
            ListNode* sgte = new ListNode(1);
            ptrNuevo->next = sgte;
        }
        else{
            digito = suma;
            ptrNuevo->val = digito;
        }

        return nuevaLista;

    }
};

int main(){
//    ListNode a7(9);
//    ListNode a6(9, &a7);
//    ListNode a5(9, &a6);
//    ListNode a4(9, &a5);
    ListNode a3(9);
    ListNode a2(4, &a3);
    ListNode a1(2, &a2);

    ListNode b4(9);
    ListNode b3(4, &b4);
    ListNode b2(6, &b3);
    ListNode b1(5, &b2);

    Solution sol;
    ListNode* rpta = sol.addTwoNumbers(&a1, &b1);

    while(rpta->next != nullptr){
        cout<<rpta->val<<" -> ";
        rpta = rpta->next;
    }
    cout<<rpta->val;


    return 0;
}