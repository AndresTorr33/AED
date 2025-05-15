#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// Solved Beats 65% in both Time and Space Complexity

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_set<int> unSet;
        int cantidad = 0, mayorCantidad = 0;

        for(auto e: nums){
            unSet.insert(e);
        }

        for(auto e : unSet){

            if(unSet.find(e-1) == unSet.end()){
                cantidad++;
                int numeroSgte = e+1;
                while(true){
                    if(unSet.find(numeroSgte) == unSet.end()) break;
                    numeroSgte++;
                    cantidad++;
                }
            }

            if(cantidad>=mayorCantidad) mayorCantidad = cantidad;
            cantidad = 0;
        }

        return mayorCantidad;
    }
};

int main(){

    Solution sol;
    vector<int> nums = {100,4,200,1,3,2};

    cout << sol.longestConsecutive(nums);

    return 0;
}


