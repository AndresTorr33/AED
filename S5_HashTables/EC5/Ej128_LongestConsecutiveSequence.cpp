#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_map<int, vector<int>> mapa;
//        int menorElemento = 0, mayorElemento = 0;
        int cantidad = 0, mayorCantidad = 0;

//        for(auto e : nums){
//            if(mapa[e].find(mapa[e].begin(), mapa[e].end(),mapa[e]))
//        }


        for(auto e : nums) {

            if(mapa[e].empty()){
                mapa[e].emplace_back(e);
            }

            if(!mapa[e+1].empty() or !mapa[e-1].empty()){
                for(auto m : mapa){
                    if(find(m.second.begin(), m.second.end(), e+1) != m.second.end()){
                        m.second.emplace_back(e);
                    }
                    else if(find(m.second.begin(), m.second.end(), e-1) != m.second.end()){
                        m.second.emplace_back(e);
                    }
                }
            }


        }

        for(auto e : mapa) {
            cantidad = e.second.size();
            if(cantidad>=mayorCantidad) mayorCantidad = cantidad;
        }



//        int elemActual = menorElemento;
//        for(int i=0; i<mapa.size(); i++){
//            if(i==0){
//                if (mapa[menorElemento] >= 1){
//                    cantidad++;
//                    mapa[menorElemento] -= mapa[menorElemento];
//                }
//            }
//            else if(mapa[elemActual+1] >= 1 ){
//                cantidad++;
//                mapa[elemActual+1] -= mapa[elemActual+1];
//                elemActual = elemActual+1;
//            }
//            else if(elemActual == mayorElemento){
//                break;
//            }
//            else{
//                auto it = find(nums.begin(), nums.end(), elemActual);
//                if(it == nums.end()){
//                    cantidad++;
//                    break;
//                }
//                elemActual = *it;
//                if(cantidad>=mayorCantidad) mayorCantidad = cantidad;
//                cantidad = 1;
//            }
//        }
//        if(cantidad>=mayorCantidad) mayorCantidad = cantidad;

        return mayorCantidad;
    }
};




int main(){

    Solution sol;
    vector<int> nums = {100,4,200,1,3,2};

    cout << sol.longestConsecutive(nums);

    return 0;
}

