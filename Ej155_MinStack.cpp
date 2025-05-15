#include <iostream>
#include <stack>

using namespace std;

class MinStack {
public:

    stack<int> st;
    stack<int> stackOfMinimums;

    MinStack() {}

    void push(int val) {
        st.push(val);
        if(stackOfMinimums.empty()){
            stackOfMinimums.push(val);
        }
        else if(val<stackOfMinimums.top()){
            stackOfMinimums.push(val);
        }
        else{
            stackOfMinimums.push(stackOfMinimums.top());
        }
    }

    void pop() {
        st.pop();
        stackOfMinimums.pop();
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return stackOfMinimums.top();
    }

    ~MinStack();
};

MinStack::~MinStack() {

}


int main(){
    MinStack* obj = new MinStack();
    obj->push(-2);
    obj->push(0);
    obj->push(-3);
    cout<<obj->getMin()<<endl;
    obj->pop();
    cout<<obj->top()<<endl;
    cout<<obj->getMin()<<endl;

    return 0;
}
/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
