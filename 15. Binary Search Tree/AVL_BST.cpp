#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct TreeNode
{
    int val;
    int height;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), height(1), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), height(1), left(nullptr), right(nullptr) {}
};

class AVL
{
private:
    TreeNode *root;

    int height(TreeNode *node)
    {
        return node ? node->height : 0;
    }

    int balanceFactor(TreeNode *node)
    {
        return node ? height(node->left) - height(node->right) : 0;
    }

    /* ---------- ROTATIONS ---------- */

    TreeNode *rightRotate(TreeNode *y)
    {
        TreeNode *x = y->left;
        TreeNode *T2 = x->right;

        // Rotation
        x->right = y;
        y->left = T2;

        // Update heights
        y->height = 1 + max(height(y->left), height(y->right));
        x->height = 1 + max(height(x->left), height(x->right));

        return x;
    }

    TreeNode *leftRotate(TreeNode *x)
    {
        TreeNode *y = x->right;
        TreeNode *T2 = y->left;

        // Rotation
        y->left = x;
        x->right = T2;

        // Update heights
        x->height = 1 + max(height(x->left), height(x->right));
        y->height = 1 + max(height(y->left), height(y->right));

        return y;
    }

    /* ---------- INSERT ---------- */

    TreeNode *insert(TreeNode *node, int value)
    {
        // Normal BST insert
        if (!node)
            return new TreeNode(value);

        if (value < node->val)
            node->left = insert(node->left, value);
        else if (value > node->val)
            node->right = insert(node->right, value);
        else
            return node; // No duplicates

        // Update height
        node->height = 1 + max(height(node->left), height(node->right));

        int bf = balanceFactor(node);

        // LL Case
        if (bf > 1 && value < node->left->val)
            return rightRotate(node);

        // RR Case
        if (bf < -1 && value > node->right->val)
            return leftRotate(node);

        // LR Case
        if (bf > 1 && value > node->left->val)
        {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // RL Case
        if (bf < -1 && value < node->right->val)
        {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

public:
    AVL() : root(nullptr) {}

    void insert(int value)
    {
        root = insert(root, value);
    }

    TreeNode *getRoot()
    {
        return root;
    }
};

/* ---------- INORDER ---------- */

void inorder(TreeNode *root)
{
    if (!root)
        return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}


int main()
{
    AVL b1;
    b1.insert(6);
    b1.insert(3);
    b1.insert(1);
    b1.insert(4);
    b1.insert(9);
    b1.insert(7);
    b1.insert(8);
    b1.insert(10);

    inorder(b1.getRoot());

    return 0;
}
