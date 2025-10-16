// 1038. Binary Search Tree to Greater Sum Tree
// Problem:
// Given the root of a Binary Search Tree (BST), convert it to a Greater Sum Tree such that
// every key of the original BST is changed to the original key plus sum of all keys greater than it.
//
// Link: `https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/`
//
// Constraints (LeetCode):
// - The number of nodes in the tree is in the range [1, 100].
// - -10^4 <= Node.val <= 10^4
//
// Expected Complexity:
// - Reverse inorder traversal or Morris variant: Time O(n)
// - Space: O(h) recursion or O(1) for Morris traversal

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
    TreeNode* bstToGst(TreeNode* root) {
        int sum = 0;
        Helper(root, sum);
        return root;
    }
};

// Solution2 Complexity (Morris reverse inorder):
// - Time: O(n)
// - Space: O(1)

class Solution2
{
public:
    TreeNode *bstToGst(TreeNode *root)
    {
        int sum = 0;
        TreeNode *curr = root;

        while (curr)
        {
            if (curr->right == nullptr)
            {
                // No right subtree → process node directly
                sum += curr->val;
                curr->val = sum;
                curr = curr->left;
            }
            else
            {
                // Find the inorder predecessor of curr (leftmost node in right
                // subtree)
                TreeNode *pred = curr->right;
                while (pred->left && pred->left != curr)
                {
                    pred = pred->left;
                }

                if (pred->left == nullptr)
                {
                    // Create temporary link back to curr
                    pred->left = curr;
                    curr = curr->right;
                }
                else
                {
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