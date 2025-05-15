// Problem 2: Merge Two AVL Trees (Intersection - Only Common Values)
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    int val, height;
    Node* left;
    Node* right;
    Node(int x) : val(x), height(1), left(nullptr), right(nullptr) {}
};

// Utility functions
int getHeight(Node* node) {
    return node ? node->height : 0;
}

int getBalance(Node* node) {
    return node ? getHeight(node->left) - getHeight(node->right) : 0;
}

void updateHeight(Node* node) {
    if (node) {
        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    }
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = std::max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = std::max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}


Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = std::max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = std::max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}


void inorderTraversal(Node* root, vector<int>& values){
    if(!root) return;
    inorderTraversal(root->left, values);
    values.emplace_back(root->val);
    inorderTraversal(root->right, values);
}

Node* balance(Node* node) {
    updateHeight(node);
    int balanceFactor = getBalance(node);

    // Left Heavy
    if (balanceFactor > 1) {
        if (getBalance(node->left) < 0)
            node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Heavy
    if (balanceFactor < -1) {
        if (getBalance(node->right) > 0)
            node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}


Node* insertAVL(Node* node, int key){
    if (!node) return new Node(key);
    if (key < node->val)
        node->left = insertAVL(node->left, key);
    else if (key > node->val)
        node->right = insertAVL(node->right, key);
    else return node;

    return balance(node);
}

// TODO: Complete the Merge Intersection Function
Node* mergeIntersectionAVL(Node* root1, Node* root2) {
    vector<int> values1;
    vector<int> values2;
    vector<int> commonValues;

    // TODO: Perform inorder traversal of both trees
    inorderTraversal(root1, values1);
    inorderTraversal(root2, values2);

    // TODO: Collect values present in both trees
    int tamanhoMayor = (values2.size()>=values1.size() ? values2.size(): values1.size());

    for(int i=0; i<tamanhoMayor; i++){
        if(i >= values1.size()) { // Si ya se terminó el values1
            if(find(values1.begin(),values1.end(),values2[i]) == values1.end()){
                commonValues.emplace_back(values2[i]);
            }
        }
        else if(i >= values2.size()) { // Si ya se terminó el values2
            if(find(values2.begin(),values2.end(),values1[i]) == values2.end()){
                commonValues.emplace_back(values1[i]);
            }
        }
        else if(find(values2.begin(),values2.end(),values1[i]) != values2.end()){
            commonValues.emplace_back(values1[i]);
        }
    }

    // TODO: Insert common values into a new AVL tree
    Node* finalTree = nullptr;
    for(auto e : commonValues){
        finalTree = insertAVL(finalTree, e);
    }

    return finalTree;
}

// AVL Insertion
Node* insert(Node* node, int key) {
    if (!node) return new Node(key);
    if (key < node->val)
        node->left = insert(node->left, key);
    else if (key > node->val)
        node->right = insert(node->right, key);

    updateHeight(node);
    return node;
}

void inorderPrint(Node* root){
    if(!root) return;
    inorderPrint(root->left);
    cout<<root->val<<" ";
    inorderPrint(root->right);
}

// Main function for testing
int main() {
    Node* root1 = nullptr;
    root1 = insert(root1, 10);
    root1 = insert(root1, 20);
    root1 = insert(root1, 30);
    root1 = insert(root1, 40);
    root1 = insert(root1, 50);

    Node* root2 = nullptr;
    root2 = insert(root2, 15);
    root2 = insert(root2, 20);
    root2 = insert(root2, 35);
    root2 = insert(root2, 40);
    root2 = insert(root2, 60);

    Node* mergedRoot = mergeIntersectionAVL(root1, root2);
    // TODO: Print the merged tree for testing

    cout<<"Arbol AVL mergeado para los arboles:"<<endl;
    cout<<"AVL 1: ";
    inorderPrint(root1);
    cout<<endl;
    cout<<"AVL 2: ";
    inorderPrint(root2);
    cout<<endl;
    cout<<"Arbol Mergeado: ";
    inorderPrint(mergedRoot);

    return 0;
}
