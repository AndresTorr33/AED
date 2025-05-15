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

void updateHeight(Node* node) {
    if (node) {
        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    }
}

// TODO: Complete the Merge Intersection Function
Node* mergeIntersectionAVL(Node* root1, Node* root2) {
    // TODO: Perform inorder traversal of both trees
    // TODO: Collect values present in both trees
    // TODO: Insert common values into a new AVL tree
    return nullptr; // Temporary
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
    Node* root1 = nullptr;
    root1 = insert(root1, 10);
    root1 = insert(root1, 20);
    root1 = insert(root1, 30);

    Node* root2 = nullptr;
    root2 = insert(root2, 15);
    root2 = insert(root2, 20);
    root2 = insert(root2, 30);

    Node* mergedRoot = mergeIntersectionAVL(root1, root2);
    // TODO: Print the merged tree for testing

    return 0;
}
