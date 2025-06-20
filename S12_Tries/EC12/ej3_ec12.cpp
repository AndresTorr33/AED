#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

vector<int> construirPosiciones (string P){
    vector<int> posiciones;
    unordered_map<char, int> ultimaPos;
    unordered_set<char> yaAgregado;

    for (int i = 0; i < P.size(); i++) {
        ultimaPos[P[i]] = i;
    }

    for (char c : P) {
        if (yaAgregado.count(c) == 0) {
            posiciones.push_back(ultimaPos[c]);
            yaAgregado.insert(c);
        }
    }

    return posiciones;
}

vector<int> FindMatch (string w, string P){

    int n = w.size();
    int m = P.size();
    vector<int> posiciones = construirPosiciones(P);
    vector<int> matchEncontrado;

    int i=0;
    while(i<=n-m){
        int j = m - 1;
        while(j >= 0 and P[j] == w[i+j]){
            j--;
        }
        if (j >= 0){
            i += max(j - posiciones[w[i+j]], 1);
        }
        else{
            matchEncontrado.emplace_back(i);
            i++;
        }
    }

    return matchEncontrado;
}

int main(){
    string w = "aholahoholaa";
    string P = "hol";
    vector<int> matches;

    matches = FindMatch(w, P);

    for(auto e: matches){
        cout<<e<<" ";
    }
    cout<<endl;

    return 0;
}
