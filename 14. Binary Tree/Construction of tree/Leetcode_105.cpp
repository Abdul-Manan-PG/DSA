// 105. Build Binary Tree from array of preorder and inorder

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<int, int> inorderIndex; // map to store index of inorder values
    int preorderIndex = 0;

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // store the index of each value in inorder for O(1) lookup
        for (int i = 0; i < inorder.size(); i++) {
            inorderIndex[inorder[i]] = i;
        }
        return build(preorder, 0, inorder.size() - 1);
    }

private:
    TreeNode* build(vector<int>& preorder, int inLeft, int inRight) {
        if (inLeft > inRight) return nullptr;

        // root is the current element in preorder
        int rootVal = preorder[preorderIndex++];
        TreeNode* root = new TreeNode(rootVal);

        // find index of root in inorder
        int idx = inorderIndex[rootVal];

        // recursively build left and right subtrees
        root->left = build(preorder, inLeft, idx - 1);
        root->right = build(preorder, idx + 1, inRight);

        return root;
    }
};
