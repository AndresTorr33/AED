#include <iostream>

using namespace std;

//struct ListNode {
//    int val;
//    ListNode *next;
//    ListNode *prev;
//    ListNode() : val(0), next(nullptr), prev(nullptr) {}
//    ListNode(int x) : val(x), next(nullptr), prev(nullptr) {}
//    ListNode(int x, ListNode *next, ListNode *prev) : val(x), next(next), prev(prev) {}
//};

class MyLinkedList {
public:

    int val;
    MyLinkedList *next;
    MyLinkedList *prev;

    MyLinkedList(): val(0), next(this), prev(this) {}

    int get(int index) {
        MyLinkedList* temp = this;
        for(int i=0; i<index; i++){
            if(temp->next == nullptr) return -1;
            temp = temp->next;
        }
        return temp->val;
    }

    void addAtHead(int val) {
        MyLinkedList* newNode = new MyLinkedList();
        newNode->val = val;
        MyLinkedList* head = this;

        if(head->next == head){
            head->val = val;
        }
        else{
            newNode->next = head;
            newNode->prev = head->prev;
            head->prev = newNode;
            head = newNode;
        };
    }

    void addAtTail(int val) {

        MyLinkedList* newNode = new MyLinkedList();
        newNode->val = val;
        MyLinkedList* head = new MyLinkedList();
        head = this;
        MyLinkedList* tail = new MyLinkedList();
        tail = this;

        if(tail->next == tail){
            tail->val = val;
        }
        else{
            while(tail->next != nullptr){
                tail = tail->next;
            }
            newNode->next = head;
            newNode->prev = head->prev;
            head->prev = newNode;
            head = newNode;

            newNode->next = head->prev->next;
            newNode->prev = head->prev;
            if (tail->next) tail->next->prev = newNode;
            tail->next = newNode;
        };
//
//        newNode->prev = head->prev;
//        newNode->next = head;
//        if(head->prev) head->prev->next = newNode;
//        tail = newNode;


    }

    void addAtIndex(int index, int val) {
        MyLinkedList* newNode = new MyLinkedList();
        newNode -> val;
        MyLinkedList* head = new MyLinkedList();
        head = this;
        MyLinkedList* temp = new MyLinkedList();
        temp = this;
        bool valid = true;
        for(int i=0; i<index; i++){
            if(temp->next == nullptr){
                if(i != index-1){
                    valid = false;
                }
                break;
            }
            temp = temp->next;
        }

        if(valid){
            newNode->next = temp;
            newNode->prev = temp->prev;
            if (newNode->prev) newNode->prev->next = newNode;
            else head = newNode;
            newNode->prev = newNode;
        }

    }

    void deleteAtIndex(int index) {
        MyLinkedList* head = new MyLinkedList();
        head = this;
        MyLinkedList* nodeToDelete = new MyLinkedList();
        nodeToDelete = head;
        bool valid = true;
        for(int i=0; i<index; i++){
            if(nodeToDelete->next == nullptr){
                valid = false;
                break;
            }
            nodeToDelete = nodeToDelete->next;
        }

        if(valid){
            if (nodeToDelete->prev) nodeToDelete->prev->next = nodeToDelete->next;
            else head = nodeToDelete->next;
            if (nodeToDelete->next) nodeToDelete->next->prev = nodeToDelete->prev;
            delete nodeToDelete;
        }

    }

    void print() {
        MyLinkedList* temp = this;
        MyLinkedList* head = this;
        while (temp) {
            if(temp==head) break;
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }

};

int main(){

    MyLinkedList* obj = new MyLinkedList(); // head
    int param_1 = obj->get(1);
    obj->addAtHead(1);
    obj->addAtTail(3);
    obj->addAtIndex(2,3);
    obj->deleteAtIndex(2);

    obj->print();

}
/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */