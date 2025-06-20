#include <iostream>
#include <vector>

using namespace std;

string longestCommonPrefix (vector<string>& strs) {

    string prefijoMasLargo;

    int menorTamanhoCadena = strs[0].size();
    for(int i=1; i<strs.size(); i++){
        if (strs[i].size() < menorTamanhoCadena) menorTamanhoCadena = strs[i].size();
    }

    int hastaEsteCaracterCoincide = 0;
    for(int i=0; i<menorTamanhoCadena; i++){
        int cantPalabras = 0;
        char letraAComparar = strs[0][i];
        for(int j=0; j<strs.size(); j++){
            if(strs[j][i] == letraAComparar) cantPalabras++;
        }
        if(cantPalabras == strs.size()){
            hastaEsteCaracterCoincide++;
        }else{
            break;
        }
    }

    for(int i=0; i<hastaEsteCaracterCoincide; i++){
        prefijoMasLargo.push_back(strs[0][i]);
    }

    return prefijoMasLargo;
}

int main(){

    vector<string> strs;
    strs.emplace_back("haal");
    strs.emplace_back("hal");
    strs.emplace_back("hals");
    strs.emplace_back("halio");

    string rpta = longestCommonPrefix(strs);

    cout<<rpta;

    return 0;
}