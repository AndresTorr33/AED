// Problem 3: B-Tree Range Print by Level (Order 3)
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int ORDER = 3;

class BTreeNode {
public:
    vector<int> keys;
    vector<BTreeNode*> children;
    bool isLeaf;

    BTreeNode(bool leaf) : isLeaf(leaf) {}

    void traverse(queue<int>& nodosOrdenados) {
        size_t i = 0;
        for (; i < keys.size(); ++i) {
            nodosOrdenados.push(keys[i]);
            if (!isLeaf && i < children.size()) children[i]->traverse(nodosOrdenados);
            cout << keys[i] << " ";
        }
        if (!isLeaf && i < children.size()){
            children[i]->traverse(nodosOrdenados);
        }

    }

    void insertNonFull(int key);
    void splitChild(int i, BTreeNode* y);
    void levelOrderRange(int L, int R);
};

class BTree {
    BTreeNode* root;
public:
    BTree() { root = nullptr; }

    void traverse(queue<int>& nodosOrdenados) {
        if (root) root->traverse(nodosOrdenados);
        cout << endl;
    }

    void insert(int key);
    void printRangeByLevel(BTree &tree, int L, int R);
};

void BTree::insert(int key) {
    if (!root) {
        root = new BTreeNode(true);
        root->keys.push_back(key);
    } else {
        if (root->keys.size() == ORDER - 1) {
            BTreeNode* s = new BTreeNode(false);
            s->children.push_back(root);
            s->splitChild(0, root);
            int i = 0;
            if (s->keys[0] < key) i++;
            s->children[i]->insertNonFull(key);
            root = s;
        } else {
            root->insertNonFull(key);
        }
    }
}

void BTreeNode::insertNonFull(int key) {
    int i = keys.size() - 1;
    if (isLeaf) {
        keys.push_back(0);
        while (i >= 0 && keys[i] > key) {
            keys[i + 1] = keys[i];
            i--;
        }
        keys[i + 1] = key;
    } else {
        while (i >= 0 && keys[i] > key) i--;
        i++;
        if (children[i]->keys.size() == ORDER - 1) {
            splitChild(i, children[i]);
            if (keys[i] < key) i++;
        }
        children[i]->insertNonFull(key);
    }
}

void BTreeNode::splitChild(int i, BTreeNode* y) {
    BTreeNode* z = new BTreeNode(y->isLeaf);
    int t = (ORDER - 1) / 2;

    int midKey = y->keys[t]; // save before cut

    // Move second half of y's keys to z
    for (size_t j = t + 1; j < y->keys.size(); ++j) {
        z->keys.push_back(y->keys[j]);
    }

    // Move second half of y's children to z
    if (!y->isLeaf) {
        for (size_t j = t + 1; j < y->children.size(); ++j) {
            z->children.push_back(y->children[j]);
        }
    }

    // Trim y
    y->keys.resize(t);
    if (!y->isLeaf) {
        y->children.resize(t + 1);
    }

    children.insert(children.begin() + i + 1, z);
    keys.insert(keys.begin() + i, midKey);
}


// Use level-order traversal (e.g., with a queue) to visit each level of the tree.
void BTree::printRangeByLevel(BTree &tree, int L, int R) {
    // TODO: Implement function to print keys in range [L, R] grouped by level
    queue<int> nodosOrdenados;

    tree.traverse(nodosOrdenados);

    for(int j=0; j<nodosOrdenados.size(); j++){
        cout<<nodosOrdenados.back()<<" ";
    }
    cout<<endl;
}


int main() {
    BTree tree;
    vector<int> keys = {10, 20, 5, 6, 12, 25, 30};
    for (int key : keys) {
        tree.insert(key);
    }

    int L = 10, R = 25;
    tree.printRangeByLevel(tree, L, R);
    return 0;
}
