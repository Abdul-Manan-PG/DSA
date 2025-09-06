// 938. Range sum of BST

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
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (!root) return 0;

        if (root->val < low) {
            // skip left subtree
            return rangeSumBST(root->right, low, high);
        }
        if (root->val > high) {
            // skip right subtree
            return rangeSumBST(root->left, low, high);
        }

        // root is in range → include it and explore both sides
        return root->val +
               rangeSumBST(root->left, low, high) +
               rangeSumBST(root->right, low, high);
    }
};
