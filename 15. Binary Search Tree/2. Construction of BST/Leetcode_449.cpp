// 449. Serializa and Deserializa the BST

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec
{
public:
    // ---------- Serialize (BST → string) ----------
    string serialize(TreeNode *root)
    {
        string s;
        preorder(root, s);
        return s;
    }

    void preorder(TreeNode *root, string &s)
    {
        if (!root)
            return;
        s += to_string(root->val) + " ";
        preorder(root->left, s);
        preorder(root->right, s);
    }

    // ---------- Deserialize (string → BST) ----------
    TreeNode *deserialize(string data)
    {
        if (data.empty())
            return nullptr;
        stringstream ss(data);
        vector<int> vals;
        int val;
        while (ss >> val)
            vals.push_back(val);
        int idx = 0;
        return build(vals, idx, INT_MIN, INT_MAX);
    }

    TreeNode *build(vector<int> &vals, int &idx, int low, int high)
    {
        // Stop if index out of range OR value not within BST bounds
        if (idx == vals.size() || vals[idx] < low || vals[idx] > high)
            return nullptr;
        int val = vals[idx++];
        TreeNode *root = new TreeNode(val);
        root->left = build(vals, idx, low, val);
        root->right = build(vals, idx, val, high);
        return root;
    }
};
