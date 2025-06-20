#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {

        if(s.size() != t.size()) return false;

        unordered_map<char, int> mapa;

        for(auto c: s){
            if (mapa[c] == 0) mapa[c] = 1;
            else mapa[c]++;
        }

        for(auto c : t){
            mapa[c]--;
        }

        for(auto e : mapa){
            if(e.second != 0) return false;
        }
        return true;

    }
};

int main(){

    string s = "anamardg";
    string t = "anagramd";
    Solution sol;

    cout<<sol.isAnagram(s, t);

    return 0;
}
