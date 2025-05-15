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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        ListNode* head = new ListNode();
        ListNode* temp = new ListNode();

        if(list1 == nullptr or list2 == nullptr){
            if(list1) {
                head = list1;
                list1 = list1->next;
            }
            else if(list2){
                head = list2;
                list2 = list2->next;
            }
            else return 0;
        }
        else{
            if(list1->val < list2->val){
                head = list1;
                list1 = list1->next;
            }
            else{
                head = list2;
                list2 = list2->next;
            }
        }

        temp = head;

        while(list1 != nullptr or list2 != nullptr){
            if(list1 == nullptr){
                temp->next = list2;
                temp = temp->next;
                list2 = list2->next;
            }
            else if(list2 == nullptr){
                temp->next = list1;
                temp = temp->next;
                list1 = list1->next;
            }
            else{
                if(list1->val < list2->val){
                    temp->next = list1;
                    temp = temp->next;
                    list1 = list1->next;
                }
                else{
                    temp->next = list2;
                    temp = temp->next;
                    list2 = list2->next;
                }
            }
        }

        return head;

    }
};

int main() {

//    ListNode a3(4);
//    ListNode a2(3, &a3);
    ListNode a1(1);

//    ListNode b3(4);
//    ListNode b2(2, &b3);
    ListNode b1(2);

    Solution sol;
    ListNode* rpta = sol.mergeTwoLists(&a1, &b1);

    while(rpta->next != nullptr){
        cout<<rpta->val<<" -> ";
        rpta = rpta->next;
    }
    cout<<rpta->val;


    return 0;
}