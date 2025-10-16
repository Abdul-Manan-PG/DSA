// 94. Binary Tree Inorder Traversal
// Problem:
// Given the root of a binary tree, return the inorder traversal of its nodes' values.
//
// Link: `https://leetcode.com/problems/binary-tree-inorder-traversal/`
//
// Constraints (LeetCode):
// - The number of nodes in the tree is in the range [0, 100].
// - -100 <= Node.val <= 100
//
// Expected Complexity:
// - Recursive/Iterative traversal: Time O(n), Space O(n) worst-case

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

// Solution1 Complexity (Recursive building vectors):
// - Time: O(n)
// - Space: O(n)

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

// Solution2 Complexity (Recursive helper):
// - Time: O(n)
// - Space: O(n)

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