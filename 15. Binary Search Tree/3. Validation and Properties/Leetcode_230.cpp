// 230. Kth smallest Element in a BST

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
    int kthSmallest(TreeNode* root, int& k) {
        if (!root) return -1;
        int left = kthSmallest(root->left, k);
        if (left != -1) return left;
        --k;
        if (k == 0) return root->val;
        int right = kthSmallest(root->right, k);
        if (right != -1) return right;
        return -1;
    }
};