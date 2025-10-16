// 144. Binary Tree Preorder Traversal
// Problem:
// Given the root of a binary tree, return the preorder traversal of its nodes' values.
//
// Link: `https://leetcode.com/problems/binary-tree-preorder-traversal/`
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
    vector<int> preorderTraversal(TreeNode* root) {
        if (root == NULL) return {};
        
        vector<int> ans;
        ans.push_back(root->val); // Root val
        
        vector<int> left = preorderTraversal(root->left); // left traversal
        for (int num : left)
        {
            ans.push_back(num);
        }

        vector<int> right = preorderTraversal(root->right); // rigth traversal
        for (int num : right){
            ans.push_back(num);
        }
        
        return ans;
    }
};

// Solution2 Complexity (Iterative with stack):
// - Time: O(n)
// - Space: O(n)

class Solution2 {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (!root) return ans;
        stack<TreeNode*> stk;
        stk.push(root);
        while (!stk.empty()) {
            TreeNode* node = stk.top();
            stk.pop();
            ans.push_back(node->val);
            if (node->right) stk.push(node->right);
            if (node->left) stk.push(node->left);
        }
        return ans;
    }
};

// Solution3 Complexity (Recursive helper):
// - Time: O(n)
// - Space: O(n)


class Solution3 {
    public:
    void preorderHelper(TreeNode* root, vector<int>& ans) {
        if (!root) return;
        ans.push_back(root->val);
        preorderHelper(root->left, ans);
        preorderHelper(root->right, ans);
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        preorderHelper(root, ans);
        return ans;
    }
};