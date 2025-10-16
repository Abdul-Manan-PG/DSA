// 701. Insert into a Binary Search Tree
// Problem:
// You are given the root node of a binary search tree (BST) and a value to insert into the tree.
// Insert the value and return the root node of the BST. The insertion must maintain the BST property.
//
// Link: `https://leetcode.com/problems/insert-into-a-binary-search-tree/`
//
// Constraints (LeetCode):
// - The number of nodes in the tree is in the range [0, 10^4].
// - -10^8 <= Node.val <= 10^8
// - All the values Node.val are unique.
//
// Expected Complexity:
// - Iterative or recursive insertion: Time O(h), Space O(1) iterative or O(h) recursion

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

// Solution1 Complexity (Iterative insertion):
// - Time: O(h)
// - Space: O(1)

class Solution1
{
public:
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        if (!root)
        {
            return new TreeNode(val);
        }

        TreeNode *insert = root;
        TreeNode *parent;

        while (insert)
        {
            parent = insert;
            if (val < insert->val)
                insert = insert->left;
            else
                insert = insert->right;
        }

        if (val < parent->val)
            parent->left = new TreeNode(val);
        else
            parent->right = new TreeNode(val);

        return root;
    }
};

// Solution2 Complexity (Recursive insertion):
// - Time: O(h)
// - Space: O(h)

class Solution2
{
public:
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        if (!root)
        {
            return new TreeNode(val);
        }

        if (val < root->val)
            root->left = insertIntoBST(root->left, val);
        
        else
            root->right = insertIntoBST(root->right, val);
        
        return root;
    }
};