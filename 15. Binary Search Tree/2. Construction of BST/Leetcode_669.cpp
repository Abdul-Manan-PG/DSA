// 669. Trim a binary Search Tree

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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if (!root) return nullptr;

        // If current node's value is less than low, discard left subtree
        if (root->val < low) {
            return trimBST(root->right, low, high);
        }
        // If current node's value is greater than high, discard right subtree
        if (root->val > high) {
            return trimBST(root->left, low, high);
        }

        // Otherwise, recursively trim left and right subtrees
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);
        return root;
    }
};
