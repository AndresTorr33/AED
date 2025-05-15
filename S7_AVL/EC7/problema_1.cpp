// Problem 1: K-th Smallest Element in an AVL Tree
#include <iostream>
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

void updateHeight(Node* node) {
    if (node) {
        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    }
}

// TODO: Complete the K-th Smallest function
int findKthSmallest(Node* root, int k) {
    // TODO: Implement inorder traversal to find the K-th smallest element
    if (!root) return 0;
    findKthSmallest(root->left, k);
    cout << root->val << " ";
    findKthSmallest(root->right, k);

    return -1; // Temporary
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

// Main function for testing
int main() {
    Node* root = nullptr;
    root = insert(root, 20);
    root = insert(root, 10);
    root = insert(root, 30);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 25);
    root = insert(root, 35);

    // Testing the K-th smallest function
    for (int k = 1; k <= 7; ++k) {
        cout << "The " << k << "-th smallest element is: " 
             << findKthSmallest(root, k) << endl;
    }

    return 0;
}
