#include <iostream>
#include <cmath>

using namespace std;

// DONE!

int main(){
    // Usamos un string para que pueda aceptar 0 al frente
    string numeroBinario = "11111111";
    int numeroEnDecimal=0;

    int i=0;
    for(auto e : numeroBinario){
        if(e == '1') numeroEnDecimal+=pow(2,numeroBinario.size()-1-i);
        i++;
    }

    cout<<numeroEnDecimal;


    return 0;
}