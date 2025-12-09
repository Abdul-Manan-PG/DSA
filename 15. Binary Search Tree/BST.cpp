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

class BST_iterative
{
    TreeNode *root;

public:
    BST_iterative()
    {
        root = NULL;
    }
    void insert(int val)
    {
        if (!root)
        {
            root = new TreeNode(val);
            return;
        }
        TreeNode *rptr = root;
        while (true)
        {
            if (val > rptr->val)
            {
                if (!rptr->right)
                {
                    rptr->right = new TreeNode(val);
                    break;
                }
                rptr = rptr->right;
            }
            else
            {
                if (!rptr->left)
                {
                    rptr->left = new TreeNode(val);
                    break;
                }
                rptr = rptr->left;
            }
        }
    }
    int find_max()
    {
        if (!root)
            return -1;
        TreeNode *rptr = root;
        while (rptr->right)
        {
            rptr = rptr->right;
        }
        return rptr->val;
    }
    int find_min()
    {
        if (!root)
            return -1;
        TreeNode *rptr = root;
        while (rptr->left)
        {
            rptr = rptr->left;
        }
        return rptr->val;
    }
    bool search(int val)
    {
        if (!root)
            return false;
        TreeNode *rptr = root;
        while (rptr)
        {
            if (rptr->val == val)
                return true;
            if (val > rptr->val)
                rptr = rptr->right;
            else
                rptr = rptr->left;
        }
        return false;
    }
    TreeNode *get_root()
    {
        return root;
    }

    bool deleteNode(int value)
    {
        TreeNode *parent = NULL;
        TreeNode *rptr = root;

        // 1. Search for the node
        while (rptr && rptr->val != value)
        {
            parent = rptr;
            if (value < rptr->val)
                rptr = rptr->left;
            else
                rptr = rptr->right;
        }

        
        if (!rptr)
            return false;
        
        if (rptr->left && rptr->right)
        {
            TreeNode *succParent = rptr;
            TreeNode *succ = rptr->right;

            // Find succesoor
            while (succ->left)
            {
                succParent = succ;
                succ = succ->left;
            }

            rptr->val = succ->val;
            if (succParent->left == succ)
                succParent->left = succ->right;
            else
                succParent->right = succ->right;

            delete succ;
            return true;
        }
        TreeNode *child;
        if (rptr->left)
            child = rptr->left;
        else
            child = rptr->right;

        if (!parent)
        {
            root = child;
        }
        else if (parent->left == rptr)
        {
            parent->left = child;
        }
        else
        {
            parent->right = child;
        }

        delete rptr;
        return true;
    }

    TreeNode *getRoot()
    {
        return root;
    }
    int height(TreeNode *node)
    {
        if (!node)
        {
            return 0;
        }
        if (!node->left && !node->right)
        {
            return 1;
        }
        int left = height(node->left);
        int right = height(node->right);
        return 1 + max(left, right);
    }
    int balanceFactor(int value)
    {
        TreeNode *rptr = root;
        while (rptr && rptr->val != value)
        {
            if (value < rptr->val)
            {
                rptr = rptr->left;
            }
            else
                rptr = rptr->right;
        }
        if (!rptr)
            return -404;
        int left = height(rptr->left);
        int right = height(rptr->right);
        return right - left;
    }
};

void inorder(TreeNode *root)
{
    if (!root)
        return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

void preorder(TreeNode *root)
{
    if (!root)
        return;
    cout << root->val << " ";
    inorder(root->left);
    inorder(root->right);
}

void postorder(TreeNode *root)
{
    if (!root)
        return;
    inorder(root->left);
    inorder(root->right);
    cout << root->val << " ";
}

int main()
{
    BST_iterative b1;
    b1.insert(6);
    b1.insert(3);
    b1.insert(1);
    b1.insert(4);
    b1.insert(9);
    b1.insert(7);
    b1.insert(8);
    b1.insert(10);

    inorder(b1.get_root());
    cout << endl;
    cout << b1.search(9);
    cout << b1.search(6);
    cout << b1.search(11);
    cout << endl;

    cout << "hieght = " << b1.height(b1.get_root()) << endl;
    cout << "balance factor of 9 = " << b1.balanceFactor(9) << endl;
    cout << "balance factor of 6 = " << b1.balanceFactor(6) << endl;
    cout << "balance factor of 4 = " << b1.balanceFactor(4) << endl;

    b1.deleteNode(6);
    inorder(b1.get_root());

    return 0;
}