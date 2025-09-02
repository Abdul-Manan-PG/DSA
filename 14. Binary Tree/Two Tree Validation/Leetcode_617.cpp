// 617. Merge two binary trees 

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution1 {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (!root1 && !root2) {
            return nullptr;
        } 
        else if (root1 && root2) {
            TreeNode* root = new TreeNode(root1->val + root2->val);
            root->left = mergeTrees(root1->left, root2->left);
            root->right = mergeTrees(root1->right, root2->right);
            return root;
        } 
        else if (root1) {
            TreeNode* root = new TreeNode(root1->val);
            root->left = mergeTrees(root1->left, nullptr);
            root->right = mergeTrees(root1->right, nullptr);
            return root;
        } 
        else { // only root2 is non-null
            TreeNode* root = new TreeNode(root2->val);
            root->left = mergeTrees(nullptr, root2->left);
            root->right = mergeTrees(nullptr, root2->right);
            return root;
        }
    }
};

class Solution2 {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (!root1) return root2;
        if (!root2) return root1;

        root1->val += root2->val;
        root1->left = mergeTrees(root1->left, root2->left);
        root1->right = mergeTrees(root1->right, root2->right);
        return root1;
    }
};
