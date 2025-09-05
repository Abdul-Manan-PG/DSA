// 559. Maximum Depth of N-ary Tree

#include <iostream>
#include <vector>
#include <N_ary_Node.h>
using namespace std;

class Solution {
public:
    int maxDepth(Node* root) {
        if (!root) return 0;
        if (root->children.empty()) return 1;
        int depth = 0;
        for (Node* node : root->children){
            int nodeDepth = maxDepth(node);
            depth = max(nodeDepth, depth);
        }
        return depth + 1;
    }
};