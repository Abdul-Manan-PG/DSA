// all in one traversal

#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class solution{
public:
    void Traversal (TreeNode* root, vector<int>& pre, vector<int>& post, vector<int>& in){\
        if (!root) return;

        pre.push_back(root->val);

        Traversal(root->left, pre, post, in);

        in.push_back(root->val);

        Traversal(root->left, pre, post, in);

        post.push_back(root->val);
    }
};