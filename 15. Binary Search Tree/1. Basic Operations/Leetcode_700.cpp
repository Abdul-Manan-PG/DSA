// 700. Search in a Binary Search Tree
// Problem:
// Given the root of a binary search tree (BST) and an integer val, find the node in the BST
// whose value equals val and return the subtree rooted with that node. If such a node does not
// exist, return null.
//
// Link: `https://leetcode.com/problems/search-in-a-binary-search-tree/`
//
// Constraints (LeetCode):
// - The number of nodes in the tree is in the range [1, 5000].
// - -10^4 <= Node.val, val <= 10^4
//
// Expected Complexity:
// - Recursive or iterative BST search: Time O(h) where h is tree height; Space O(h) recursion or O(1) iterative

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Solution1 Complexity (Recursive search):
// - Time: O(h)
// - Space: O(h)

class Solution1 {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (!root) return nullptr;
        if (root->val == val) return root;
        if (val < root->val) return searchBST(root->left, val);
        if (val > root->val) return searchBST(root->right, val);
        return nullptr;
    }
};

// Solution2 Complexity (Iterative search):
// - Time: O(h)
// - Space: O(1)

class Solution2 {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        while (root) {  // keep traversing until root becomes null
            if (root->val == val) {
                return root;
            }
            if (val < root->val) {
                root = root->left;
            } else {
                root = root->right;
            }
        }
        return nullptr; // not found
    }
};
