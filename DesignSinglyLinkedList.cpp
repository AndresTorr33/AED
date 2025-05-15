#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class ListNode{
public:
    int val;
    ListNode* nextPtr = nullptr;

    ListNode(int val){
        this->val = val;
    }

    ListNode(int _val, ListNode* _ptr){
        val = _val;
        nextPtr = _ptr;
    }

};

class LinkedList {
public:

    ListNode* head; // Es una direcc de memoria de tipo ListNode
    ListNode* tail;

    LinkedList() {
        head = new ListNode(-1);
        tail = head;
    }

    int get(int index) {
        ListNode* cur = head;
        for(int i=0; i<index; i++){
            if(cur->nextPtr == nullptr) return -1;
            cur = cur->nextPtr;
        }
        return cur->val;
    }

    void insertHead(int _val) {
        ListNode* tempPtr = head; // Es un tempPtr
        ListNode* newHead;
        newHead->val = _val;
        newHead->nextPtr = tempPtr;
        if(newHead->nextPtr == nullptr){
            tail = newHead;
        }
    }

    void insertTail(int _val) {
        ListNode* newTail = new ListNode(_val);
        tail->nextPtr = newTail;
        tail = tail->nextPtr;
    }

    bool remove(int index) {
        ListNode* cur = head;
        for(int i=0; i<index-1; i++){
            if(!cur->nextPtr) return false;
            cur = cur->nextPtr;
        }
        cur->nextPtr = cur->nextPtr->nextPtr;
        return true;
    }

    vector<int> getValues() {
        vector<int> valores={};
        ListNode* cur = head;
        while (true) {
            if (cur->nextPtr == nullptr) break;
            valores.emplace_back(cur->val);
        }
        return valores;
    }
};


int main(){

    ListNode cabeza(1);
    ListNode cola(5);

    LinkedList *ls = new LinkedList;
    ls->head = &cabeza;
    ls->tail = &cola;

    return 0;
}