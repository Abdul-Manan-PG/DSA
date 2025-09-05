// 590. N-ary Tree Post Order Traversal

#include <iostream>
#include <vector>
#include <N_ary_Node.h>
using namespace std;

class Solution {
public:
    void postOrderHelper(Node* root, vector<int>& ans) {
        if (!root)
            return;
        for (Node* node : root->children) {
            postOrderHelper(node, ans);
        }
        ans.push_back(root->val);
    }
    vector<int> postorder(Node* root) {
        vector<int> ans;
        postOrderHelper(root, ans);
        return ans;
    }
};