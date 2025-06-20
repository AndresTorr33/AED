#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int* keys; // array de llaves
    Node** children; // array de punteros a hijos
    int count; // cantidad de llaves en el nodo actual
    bool leaf; // indicador de nodo hoja
// (si es true , el nodo actual es hoja )

    int size(){

    }
};

class BTree {
    Node* root ;
    void range_query_r(Node* node , vector<int >& result, int k1, int k2) {
// poner su solucion aqui
    }
public:
    vector<int> range_query(int k1, int k2) {
        vector<int> result ;
        if (root == nullptr) {
            return result ;
        }
        range_query_r (this -> root, result, k1, k2);
        return result;
    }

    void range_query_r(Node root, vector<int>& result, int k1, int k2){
        size_t i = 0;
        for (; i < root.keys.size(); ++i) {
            if (!leaf && i < children.size()) children[i]->range_query_r(root, result, k1, k2);
            result.emplace_back(keys[i])
            cout << keys[i] << " ";
        }
        if (!leaf && i < children.size()) children[i]->range_query_r(root, result, k1, k2);
    }
};

int main() {





    return 0;
}
