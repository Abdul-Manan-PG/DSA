// 257. Binary Tree Paths

#include <iostream>
#include <vector>
#include <string>
#include <14. Binary Tree/TreeNode.h>
using namespace std;

class Solution2 {
    void dfs(TreeNode* node, string path, vector<string>& ans) {
        if (!node) return;
        if (!node->left && !node->right) {
            ans.push_back(path + to_string(node->val));
            return;
        }
        path += to_string(node->val) + "->";
        dfs(node->left, path, ans);
        dfs(node->right, path, ans);
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        dfs(root, "", ans);
        return ans;
    }
};

class Solution1 {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if (!root) return {};
        vector<string> left = binaryTreePaths(root->left);
        vector<string> right = binaryTreePaths(root->right);
        vector<string> ans;
        if (left.empty() && right.empty()) return {to_string(root->val)};
        if (!left.empty()){
            for (string s : left){
                string path = to_string(root->val);
                path += ("->" + s);
                ans.push_back(path);
            }
        }
        if (!right.empty()){
            for (string s : right){
                string path = to_string(root->val);
                path += ("->" + s);
                ans.push_back(path);
            }
        }
        return ans;
    }
};