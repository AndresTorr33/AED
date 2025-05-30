#include <iostream>  
#include <algorithm> // Para max()  
using namespace std;

// Definición del nodo
struct Node {  
    int data;  
    Node* left;  
    Node* right;  
    Node(int value) : data(value), left(nullptr), right(nullptr) {}  
};  

// Prototipo de la función
int diameterOfBinaryTree(Node* root);

// Función principal para probar la solución
int main() {
    // Nota: Este main es solo para ejemplo y no refleja todos los casos de prueba.
    // Los estudiantes deben probar su función con otros casos también.

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    // Llamada a la función y salida
    cout << "El diámetro del árbol es: " << diameterOfBinaryTree(root) << endl;
    return 0;
}

int height(Node* node, int& diameter) {
    // Se pone un caso inicial para el caso donde el nodo sea nulo
    if (node == nullptr) return 0;


    int leftHeight = height(node->left, diameter);
    int rightHeight = height(node->right, diameter);

    // La función actualiza el diámetro si a través de esta ruta es mayor
    diameter = max(diameter, leftHeight + rightHeight + 1);

    // Se usa la función max para retornar la altura de este nodo
    return max(leftHeight, rightHeight) + 1;
}

// Implementa tu función aquí
int diameterOfBinaryTree(Node* root) {
    // Tu código aquí
    // Se inicializa el diámetro en 0
    int diameter = 0;
    // Se llama a una función auxiliar
    height(root, diameter);
    return diameter;
}

