#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {

        unordered_map<int,int> mapita;
        bool contiene = false;

        for(auto e : nums){
            mapita[e] = 0;
        }

        for(auto e : nums){
            mapita[e] += 1;
            if(mapita[e]>1) contiene = true;
        }

//        // Encontrar si hay duplicado
//        for(auto e : mapita){
//            cout<<e.first<<". "<<e.second<<endl;
//        }
//        cout<<endl;
//
//        //-------------IMPRESION---------------//
//        for(auto e : mapita){
//            cout<<e.first<<". "<<e.second<<endl;
//        }
//        //-------------IMPRESION---------------//

        return contiene;
    }


};


int main(){

    Solution sol;
    vector<int> nums = {1,1,1,3,3,4,3,2,4,2};

    cout << sol.containsDuplicate(nums);

    return 0;
}