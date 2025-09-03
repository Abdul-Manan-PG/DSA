// 102. Binary Tree Level Order Traversal

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        int order = 0;
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        ans.push_back({});
        q.push(root);
        q.push(NULL);
        while (q.size() > 0) {
            TreeNode* node = q.front();
            q.pop();
            if (!node){
                if (q.empty()){
                    break;
                }
                else{
                    q.push(NULL);
                    ans.push_back({});
                    order++;
                    continue;
                }
            }
            
            ans[order].push_back(node->val);
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        return ans;
    }
};