#include <iostream>
#include <queue>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


TreeNode* search(TreeNode* root, int val, vector<int>& vec) {
    if (!root || root->val == val){
        vec.emplace_back(root->val);
        return root;
    }

    vec.emplace_back(root->val);
    if (val < root->val){
        return search(root->left, val, vec);
    }
    else{
        return search(root->right, val, vec);
    }
}

class Solution {
public:


    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<int> vectorP = {};
        vector<int> vectorQ = {};

        search(root, p->val, vectorP);
        search(root, q->val, vectorQ);

        int tamanhoMayor = (vectorQ.size()>=vectorP.size() ? vectorQ.size(): vectorP.size());

        for(int i=0; i<tamanhoMayor; i++){
            if(i == vectorP.size()) return new TreeNode(vectorQ[i-1]);
            if(i == vectorQ.size()) return new TreeNode(vectorP[i-1]);
            if(vectorP[i] != vectorQ[i]){
                return new TreeNode(vectorP[i-1]);
            }
        }
        return nullptr;
    }
};

int main() {
    TreeNode* root = new TreeNode(6);
    TreeNode* p = new TreeNode(2);
    TreeNode* q = new TreeNode(4);

    root->left = p;
    root->right = new TreeNode(8);

    root->left->left = new TreeNode(0);
    root->left->right = q;
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);

    root->left->right->left = new TreeNode(3);
    root->left->right->right = new TreeNode(5);

/*
        10
       /  \
      5    15
     / \
    3   6
*/
    Solution sol;
    cout<<sol.lowestCommonAncestor(root, p, q)->val;
}

