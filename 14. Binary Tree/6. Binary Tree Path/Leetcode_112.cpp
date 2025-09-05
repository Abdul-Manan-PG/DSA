// 112. Path Sum

#include <iostream>
#include <vector>
#include <string>
#include <14. Binary Tree/TreeNode.h>
using namespace std;


class Solution {
public:
    void dfs(TreeNode* node, int path, vector<int>& ans) {
        if (!node) return;
        if (!node->left && !node->right) {
            ans.push_back(path + node->val);
            return;
        }
        path += node->val;
        dfs(node->left, path, ans);
        dfs(node->right, path, ans);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        vector<int> ans;
        dfs(root, 0, ans);
        for (int num : ans){
            if (num == targetSum){
                return true;
            }
        }
        return false;
    }
};