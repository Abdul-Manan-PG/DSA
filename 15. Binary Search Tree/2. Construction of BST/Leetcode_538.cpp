// 538. Convert BST to Greater Tree
// Problem:
// Given the root of a Binary Search Tree (BST), convert it to a Greater Tree such that
// the value of every node is changed to the original value plus the sum of values
// of all nodes greater than it.
//
// Link: `https://leetcode.com/problems/convert-bst-to-greater-tree/`
//
// Constraints (LeetCode):
// - The number of nodes in the tree is in the range [0, 10^4].
// - -10^4 <= Node.val <= 10^4
//
// Expected Complexity:
// - Reverse inorder traversal or Morris variant: Time O(n)
// - Space: O(h) recursion or O(1) with Morris

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

// Solution1 Complexity (Reverse inorder recursion):
// - Time: O(n)
// - Space: O(h)

class Solution1 // 100% time beat
{
public:
    void Helper(TreeNode* root, int& sum){
        if (!root) return;
        Helper(root->right, sum);
        sum += root->val;
        root->val = sum;
        Helper(root->left, sum);
    }
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        Helper(root, sum);
        return root;
    }
};

// Solution2 Complexity (Morris traversal):
// - Time: O(n)
// - Space: O(1)

class Solution2 {
public:
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        TreeNode* curr = root;

        while (curr) {
            if (curr->right == nullptr) {
                // No right subtree → process node directly
                sum += curr->val;
                curr->val = sum;
                curr = curr->left;
            } else {
                // Find the inorder predecessor of curr (leftmost node in right subtree)
                TreeNode* pred = curr->right;
                while (pred->left && pred->left != curr) {
                    pred = pred->left;
                }

                if (pred->left == nullptr) {
                    // Create temporary link back to curr
                    pred->left = curr;
                    curr = curr->right;
                } else {
                    // Restore tree (remove link) & process current node
                    pred->left = nullptr;
                    sum += curr->val;
                    curr->val = sum;
                    curr = curr->left;
                }
            }
        }
        return root;
    }
};
