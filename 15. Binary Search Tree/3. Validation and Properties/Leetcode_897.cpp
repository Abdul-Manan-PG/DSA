// 897. Increasing Order Search Tree

#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* dummy = new TreeNode(0);
        TreeNode* curr = dummy;
        inorder(root, curr);
        return dummy->right;
    }

private:
    void inorder(TreeNode* node, TreeNode*& curr) {
        if (!node) return;
        inorder(node->left, curr);
        node->left = nullptr;
        curr->right = node;
        curr = node;
        inorder(node->right, curr);
    }
};
