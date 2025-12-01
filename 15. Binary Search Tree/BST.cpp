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
            root = new TreeNode(val);
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
            else{
                if (!rptr->left)
                {
                    rptr->left = new TreeNode(val);
                    break;
                }
                rptr = rptr->left;
            }
        }
    }
    int find_max(){
        if (!root) return -1;
        TreeNode* rptr = root;
        while (rptr->right){
            rptr = rptr->right;
        }
        return rptr->val;
    }
    int find_min(){
        if (!root) return -1;
        TreeNode* rptr = root;
        while (rptr->left){
            rptr = rptr->left;
        }
        return rptr->val;
    }
    bool search(int val){
        if (!root) return false;
        TreeNode* rptr = root;
        while (rptr){
            if (rptr->val == val) return true;
            if (val > rptr->val) rptr = rptr->right;
            else rptr = rptr->left;
        }
        return false;
    }
    TreeNode* get_root(){
        return root;
    }
};

void inorder(TreeNode* root){
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

void preorder(TreeNode* root){
    if (!root) return;
    cout << root->val << " ";
    inorder(root->left);
    inorder(root->right);
}

void postorder(TreeNode* root){
    if (!root) return;
    inorder(root->left);
    inorder(root->right);
    cout << root->val << " ";
}