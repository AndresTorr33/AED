#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// Esto solo soluciona la mayor distancia entre 2 caracteres iguales en la cadena
// No la mayor longitud de subcadena sin repetir caracteres.
//class Solution {
//public:
//    int lengthOfLongestSubstring(string s) {
//        int maxLong = 0;
//        unordered_map<char, vector<int>> mapa;
//        int i=0;
//        for(auto c : s){
//            if(mapa[c].empty()) mapa[c] = {i};
//            else{
//                if(mapa[c].size()==1) mapa[c].emplace_back(i);
//                else{
//                    if(i-mapa[c][1] > mapa[c][1]-mapa[c][0]){
//                        mapa[c][0] = mapa[c][1];
//                        mapa[c][1] = i;
//                    }
//                }
//            }
//            i++;
//        }
//
//        for(auto e : mapa){
//            if(e.second.size()==1){
//                if(e.second[0] > maxLong) maxLong = e.second[0];
//            }
//            else{
//                if(e.second[1] - e.second[0] > maxLong) maxLong = e.second[1] - e.second[0];
//            }
//        }
//
//        return maxLong-1;
//    }
//};


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLong = 0;

        unordered_map<int, char> mapa;

        for(int i=0; i<s.size(); i++){
            mapa[i] = s[i];
        }

        int maximoPosible = mapa.size();

        int cont=0;
        unordered_set<char> setazo;
        for(int i=0; i<s.size(); i++){

            if(setazo[mapa[i]])
            if(mapa[cont] != mapa[cont+1]){
                maxLong++;
            }else{
                cont=
            }
        }

        return maxLong-1;
    }
};

int main(){

    string s = "abcabcbb";
    Solution sol;

    cout<<sol.lengthOfLongestSubstring(s);


    return 0;
}