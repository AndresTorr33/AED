#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> answer(temperatures.size(), 0); // vector de distancias entre actual y el siguiente
        stack<int> st;

        for (int i = temperatures.size()-1; i >= 0; i--) {
            while (!st.empty() && temperatures[st.top()] <= temperatures[i])
                st.pop();

            if (!st.empty())
                answer[i] = st.top() - i; // valor actual - i

            st.push(i);
        }

        return answer;
    }

};

int main(){

    vector<int> st = {73,74,75,71,69,72,76,73};

    Solution sol;

    vector<int> answ = sol.dailyTemperatures(st);

    for(auto e: answ){
        cout<<e<<" ";
    }
    cout<<endl;


    return 0;
}