// 530. Minimum absolute difference in BST

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
    void solve(TreeNode* root, int& ans, TreeNode*& prev) {
        if (!root)
            return;
        solve(root->left, ans, prev);
        if (prev)
            ans = min(ans, root->val - prev->val);
        prev = root;
        solve(root->right, ans, prev);
    }
    int getMinimumDifference(TreeNode* root) {
        TreeNode* prev = nullptr;
        int ans = INT_MAX;
        solve(root, ans, prev);
        return ans;
    }
};