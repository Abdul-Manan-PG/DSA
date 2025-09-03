// Binary Tree Inorder Traversal

#include <iostream>
#include <vector>
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

class Solution1 {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if (root == NULL) return {};
        
        vector<int> ans;
        
        vector<int> left = inorderTraversal(root->left); // left traversal
        for (int num : left)
        {
            ans.push_back(num);
        }
        
        ans.push_back(root->val); // Root val

        vector<int> right = inorderTraversal(root->right); // rigth traversal
        for (int num : right){
            ans.push_back(num);
        }

        return ans;
    }
};

class Solution2 {
public:
    void inorderHelper(TreeNode* root, vector<int>& ans) {
        if (!root) return;
        inorderHelper(root->left, ans);
        ans.push_back(root->val);
        inorderHelper(root->right, ans);
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inorderHelper(root, ans);
        return ans;
    }
};