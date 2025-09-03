// 958. Check completness of a binary tree 

#include <iostream>
#include <vector>
#include <queue>
#include<14. Binary Tree/TreeNode.h>
using namespace std;


class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        if (root == nullptr) return true;

        std::queue<TreeNode*> q;
        q.push(root);
        bool foundNull = false;

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node == nullptr) {
                foundNull = true;
            } else {
                if (foundNull) {
                    // Found a non-null node after a null node in level order
                    return false;
                }
                q.push(node->left);
                q.push(node->right);
            }
        }
        return true;
    }
};
