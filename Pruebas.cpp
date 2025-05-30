#include <iostream>
#include <vector>
using namespace std;

const int M = 3; // B-Tree of order 3 (max 2 keys per node)

struct Node {
    vector<int> keys;               // Max keys = M-1
    vector<Node*> children;         // Max children = M
    bool isLeaf;

    Node(bool leaf) : isLeaf(leaf) {}

    void traverse() {
        size_t i = 0;
        for (; i < keys.size(); ++i) {
            if (!isLeaf && i < children.size()) children[i]->traverse();
            cout << keys[i] << " ";
        }
        if (!isLeaf && i < children.size()) children[i]->traverse();
    }

    Node* search(int k) {
        size_t i = 0;
        while (i < keys.size() && k > keys[i]) i++;
        if (i < keys.size() && keys[i] == k) return this;
        if (isLeaf) return nullptr;
        return children[i]->search(k);
    }

    void insertNonFull(int k);
    void splitChild(int i, Node* y);
};

struct BTree {
    Node* root = nullptr;

    void traverse() {
        if (root) root->traverse();
        cout << endl;
    }

    Node* search(int k) {
        return root ? root->search(k) : nullptr;
    }

    void insert(int k) {
        if (!root) {
            root = new Node(true);
            root->keys.push_back(k);
        } else {
            if (root->keys.size() == M - 1) {
                Node* s = new Node(false);
                s->children.push_back(root);
                s->splitChild(0, root);
                int i = (s->keys[0] < k) ? 1 : 0;
                s->children[i]->insertNonFull(k);
                root = s;
            } else {
                root->insertNonFull(k);
            }
        }
    }
};

void Node::insertNonFull(int k) {
    int i = keys.size() - 1;

    if (isLeaf) {
        keys.push_back(0);
        while (i >= 0 && keys[i] > k) {
            keys[i + 1] = keys[i];
            i--;
        }
        keys[i + 1] = k;
    } else {
        while (i >= 0 && keys[i] > k) i--;
        i++;
        if (children[i]->keys.size() == M - 1) {
            splitChild(i, children[i]);
            if (k > keys[i]) i++;
        }
        children[i]->insertNonFull(k);
    }
}

void Node::splitChild(int i, Node* y) {
    Node* z = new Node(y->isLeaf);
    int t = (M - 1) / 2;

    // Move keys
    for (size_t j = t + 1; j < y->keys.size(); ++j)
        z->keys.push_back(y->keys[j]);

    y->keys.resize(t);

    // Move children
    if (!y->isLeaf) {
        for (size_t j = t + 1; j < y->children.size(); ++j)
            z->children.push_back(y->children[j]);
        y->children.resize(t + 1);
    }

    children.insert(children.begin() + i + 1, z);
    keys.insert(keys.begin() + i, y->keys[t]);
}

int main() {
    BTree tree;
    int values[] = {45, 75, 100, 36, 120, 70, 111, 11, 47, 114};

    for (int val : values)
        tree.insert(val);

    cout << "Traversal:\n";
    tree.traverse();

    int k = 111;
    cout << "Searching for " << k << ": ";
    if (tree.search(k)) cout << "Found\n";
    else cout << "Not found\n";

    return 0;
}

