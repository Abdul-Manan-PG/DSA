// 450. Delete Node in a BST
// Problem:
// Given a root node reference of a BST and a key, delete the node with the given key in the BST.
// Return the root node reference of the BST (possibly updated).
//
// Link: `https://leetcode.com/problems/delete-node-in-a-bst/`
//
// Constraints (LeetCode):
// - The number of nodes in the tree is in the range [0, 10^4].
// - -10^5 <= Node.val <= 10^5
//
// Expected Complexity:
// - Deletion by BST rules: Time O(h), Space O(h) recursion or O(1) iterative

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

// Solution1 Complexity (Recursive with in-order successor handling):
// - Time: O(h)
// - Space: O(h)

class Solution1
{
public:
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (root == nullptr)
        {
            return NULL;
        }

        // Search the Node in BST
        if (key < root->val) // if node is in left tree
        {
            root->left = deleteNode(root->left, key);
            return root;
        }
        else if (key > root->val) // if node is in right tree
        {
            root->right = deleteNode(root->right, key);
            return root;
        }
        else // node founded :: deletion process
        {
            // if Node has 0 children
            if (!root->left && !root->right)
            {
                delete root;
                return NULL;
            }

            // if Node has 1 child

            else if (!root->left)
            {
                TreeNode *right = root->right;
                delete root;
                return right;
            }
            else if (!root->right)
            {
                TreeNode *left = root->left;
                delete root;
                return left;
            }

            // if ALL upper condition are wrong :: root has 2 children

            else
            {
                // 1. find the successor
                TreeNode *successor = root->right;
                while (successor->left)
                {
                    successor = successor->left;
                }
                // 2. deletion Node val = successor node val
                root->val = successor->val;
                // 3. deletetion of successor node
                root->right = deleteNode(root->right, successor->val);

                return root;
            }
        }
    }
};

// Solution2 Complexity (Recursive, clean version):
// - Time: O(h)
// - Space: O(h)

class Solution2 // clean version
{
public:
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (root == nullptr)
            return nullptr;

        if (key < root->val)
        {
            root->left = deleteNode(root->left, key);
        }
        else if (key > root->val)
        {
            root->right = deleteNode(root->right, key);
        }
        else
        {
            // Case 1: No child
            if (!root->left && !root->right)
            {
                delete root;
                return nullptr;
            }

            // Case 2: One child
            if (!root->left)
            {
                TreeNode *right = root->right;
                delete root;
                return right;
            }
            if (!root->right)
            {
                TreeNode *left = root->left;
                delete root;
                return left;
            }

            // Case 3: Two children
            TreeNode *successor = findMin(root->right);
            root->val = successor->val;
            root->right = deleteNode(root->right, successor->val);
        }
        return root;
    }

private:
    TreeNode *findMin(TreeNode *node)
    {
        while (node->left)
            node = node->left;
        return node;
    }
};
