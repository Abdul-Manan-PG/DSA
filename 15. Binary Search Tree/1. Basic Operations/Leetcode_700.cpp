// 700. Search in Binary Search Tree

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution1 {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (!root) return nullptr;
        if (root->val == val) return root;
        if (val < root->val) return searchBST(root->left, val);
        if (val > root->val) return searchBST(root->right, val);
        return nullptr;
    }
};

class Solution2 {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        while (root) {  // keep traversing until root becomes null
            if (root->val == val) {
                return root;
            }
            if (val < root->val) {
                root = root->left;
            } else {
                root = root->right;
            }
        }
        return nullptr; // not found
    }
};
