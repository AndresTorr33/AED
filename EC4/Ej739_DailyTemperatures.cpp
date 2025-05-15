#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        vector<int> answer;
        stack<int> stackTemperatures;

        // Llenar el stack "stackTemperatures" con temperatures
        for(int i=temperatures.size()-1; i>=0; i--){
            stackTemperatures.push(temperatures[i]);
        }

        for(int i=0; i<temperatures.size(); i++){

            if(i==temperatures.size()-1){
                answer.emplace_back(0);
                break;
            }
            stack<int> stackTemp = stackTemperatures;
            int temp = temperatures[i];

            for(int j=0; j<=i; j++){
                stackTemp.pop();
            }

            answer.emplace_back(0);
            int elementoTop = stackTemp.top();
            for(int k=0; k<temperatures.size()-i-1; k++){
                if(stackTemp.top() > temp){
                    answer.erase(answer.end());
                    answer.emplace_back(k+1);
                    break;
                }
                stackTemp.pop();
            }
        }
        return answer;
    }

};

int main(){

    vector<int> st = {30,60,90};

    Solution sol;

    vector<int> answ = sol.dailyTemperatures(st);

    for(auto e: answ){
        cout<<e<<" ";
    }
    cout<<endl;


    return 0;
}