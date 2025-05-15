// Problem 3: AVL Playlist Manager
#include <iostream>
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

// TODO: Complete the Playlist Functions
void AddSong(Node*& root, int score) {
    // TODO: Implement AVL insertion logic
}

void RemoveSong(Node*& root, int score) {
    // TODO: Implement AVL deletion logic
}

int GetMostPopular(Node* root) {
    // TODO: Return the maximum value (rightmost node)
    return -1;
}

int GetKthPopular(Node* root, int k) {
    // TODO: Implement reverse inorder traversal to find K-th popular
    return -1;
}

// Main function for testing
int main() {
    Node* root = nullptr;
    AddSong(root, 10);
    AddSong(root, 20);
    AddSong(root, 15);

    cout << "Most Popular: " << GetMostPopular(root) << endl;
    cout << "2nd Most Popular: " << GetKthPopular(root, 2) << endl;

    RemoveSong(root, 15);
    cout << "Most Popular after removal: " << GetMostPopular(root) << endl;

    return 0;
}
