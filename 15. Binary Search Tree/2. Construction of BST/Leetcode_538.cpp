// 538. Convert BST into Greater Tree

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
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        Helper(root, sum);
        return root;
    }
};

class Solution2 {
public:
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        TreeNode* curr = root;

        while (curr) {
            if (curr->right == nullptr) {
                // No right subtree → process node directly
                sum += curr->val;
                curr->val = sum;
                curr = curr->left;
            } else {
                // Find the inorder predecessor of curr (leftmost node in right subtree)
                TreeNode* pred = curr->right;
                while (pred->left && pred->left != curr) {
                    pred = pred->left;
                }

                if (pred->left == nullptr) {
                    // Create temporary link back to curr
                    pred->left = curr;
                    curr = curr->right;
                } else {
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
