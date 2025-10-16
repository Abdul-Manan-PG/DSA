// 617. Merge Two Binary Trees 
// Problem:
// You are given two binary trees root1 and root2. Merge them into a single binary tree by adding the values of overlapping nodes.
// If a node exists in one tree and not the other, merge it as-is.
//
// Link: `https://leetcode.com/problems/merge-two-binary-trees/`
//
// Constraints (LeetCode):
// - The number of nodes in both trees is in the range [0, 2000].
// - -10^4 <= Node.val <= 10^4
//
// Expected Complexity:
// - Recursive merge: Time O(n + m), Space O(h)

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

// Solution1 Complexity (Create new merged tree):
// - Time: O(n + m)
// - Space: O(h)

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

// Solution2 Complexity (In-place merge into root1):
// - Time: O(n + m)
// - Space: O(h)

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
