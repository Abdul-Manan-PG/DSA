// binary tree postorder traversal

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    void postorderHelper(TreeNode* root, vector<int>& ans) {
        if (!root) return;
        postorderHelper(root->left, ans);
        postorderHelper(root->right, ans);
        ans.push_back(root->val);
    }
    
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        postorderHelper(root, ans);
        return ans;
    }
};

