// 100. Same Tree 

#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Case 1: both are null -> trees are same
        if (p == nullptr && q == nullptr) return true;

        // Case 2: one is null and other is not -> trees are different
        else if (p == nullptr || q == nullptr) return false;

        // Case 3: values mismatch -> trees are different
        else if (p->val != q->val) return false;

        else // Case 4: check subtrees recursively
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};