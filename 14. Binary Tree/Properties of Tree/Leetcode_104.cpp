// 104. Maximum Depth of Binary Tree

#include <iostream>
#include <vector>
#include <string>
#include<14. Binary Tree/TreeNode.h>
using namespace std;

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL) return 0;

        int left = maxDepth(root->left);
        int right = maxDepth(root->right);

        return 1 + max(left, right);
    }
};