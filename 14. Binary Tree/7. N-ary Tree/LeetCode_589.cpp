// 589. N-ary Tree PreOrder Traversal

#include <iostream>
#include <vector>
#include <string>
#include <N_ary_Node.h>
using namespace std;

class Solution {
public:
    void preOrderHelper(Node* root, vector<int>& ans) {
        if (!root) return;
        ans.push_back(root->val);
        for (Node* node : root->children) {
            preOrderHelper(node, ans);
        }
    }

    vector<int> preorder(Node* root) {
        vector<int> ans;
        preOrderHelper(root, ans);
        return ans;
    }
};
