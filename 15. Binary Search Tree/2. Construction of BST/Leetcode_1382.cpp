// 1382. Balance a Binary Search Tree

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

class Solution1 {
public:
    void inorder(TreeNode* root, vector<int>& vals) {
        if (!root) return;
        inorder(root->left, vals);
        vals.push_back(root->val);
        inorder(root->right, vals);
    }

    TreeNode* build(vector<int>& vals, int start, int end) {
        if (start > end) return nullptr;
        int mid = start + (end - start) / 2;
        TreeNode* node = new TreeNode(vals[mid]);
        node->left = build(vals, start, mid - 1);
        node->right = build(vals, mid + 1, end);
        return node;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> vals;
        inorder(root, vals);
        return build(vals, 0, vals.size() - 1);
    }
};

int main() {
    // Example usage:
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->right = new TreeNode(3);
    root->right->right->right = new TreeNode(4);

    Solution1 solution;
    TreeNode* balancedRoot = solution.balanceBST(root);

    // Output the balanced BST in-order to verify
    vector<int> result;
    solution.inorder(balancedRoot, result);
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}