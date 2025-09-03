// 107. Binary Tree Level Order Traversal II

#include <iostream>
#include <vector>
#include <queue>
#include <14. Binary Tree/TreeNode.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (!root)
            return {};
        int order = 0;
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        ans.push_back({});
        q.push(root);
        q.push(NULL);
        while (q.size() > 0) {
            TreeNode* node = q.front();
            q.pop();
            if (!node) {
                if (q.empty()) {
                    break;
                } else {
                    q.push(NULL);
                    ans.push_back({});
                    order++;
                    continue;
                }
            }

            ans[order].push_back(node->val);
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }

        
        for (int i = 0; i < ans.size()/2;i++){
            swap(ans[i], ans[ans.size() - 1 - i]);
        }
        return ans;
    }
};