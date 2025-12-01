// 1305. All Elements in Two Binary Search Trees

// Given two binary search trees root1 and root2,
// return a list containing all the integers from both trees sorted in ascending order.


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

class Solution {
public:
    void inorder(TreeNode* root, vector<int>& ans){
        if (!root) return;
        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> ans1;
        vector<int> ans2;
        inorder(root1, ans1);
        inorder(root2, ans2);
        vector<int> ans;
        int i = 0, j = 0;
        while (i < ans1.size() && j < ans2.size()){
            if (ans1[i] < ans2[j]){
                ans.push_back(ans1[i]);
                i++;
            }
            else{
                ans.push_back(ans2[j]);
                j++;
            }
        }
        while (i < ans1.size()){
            ans.push_back(ans1[i]);
                i++;
        }
        while (j < ans2.size()){
            ans.push_back(ans2[j]);
                j++;
        }
        return ans;
    }
};