#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        char ultimoElem;
        stack<int> st;
        for(auto c : s){
            if(!st.empty()) ultimoElem = st.top();
            st.push(c);
            if(st.size()>1){
                if(c==')' and ultimoElem=='('){
                    st.pop(); st.pop();
                }
                else if(c==']' and ultimoElem=='['){
                    st.pop(); st.pop();
                }
                else if(c=='}' and ultimoElem=='{'){
                    st.pop(); st.pop();
                }
            }
        }

        for(auto c : s){
            cout<<c<<" ";
        }

        if(st.empty()) return true;
        else return false;
    }
};

int main() {

    string s = "([])";
    Solution Sol;

    Sol.isValid(s);

    return 0;
}