// 543. Diameter of Binary Tree

#include <iostream>
#include <vector>
#include <string>
#include<14. Binary Tree/TreeNode.h>
using namespace std;

class Solution {
public:
    int diameter = 0;

    int maxDepth(TreeNode* root) {
        if (root == NULL) return 0;

        int left = maxDepth(root->left);
        int right = maxDepth(root->right);

        // Update diameter at every node
        diameter = max(diameter, left + right);

        // Return height of subtree
        return 1 + max(left, right);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        maxDepth(root); // runs DFS and updates diameter
        return diameter;
    }
};
