// 701. Insert Into a Binary Search Tree

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