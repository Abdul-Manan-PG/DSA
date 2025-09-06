// 501. Find the mode in BST

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
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

class Solution1 {
public:
    vector<int> findMode(TreeNode* root) {
        if (!root) return {};  // handle empty tree

        unordered_map<int, int> freq;
        queue<TreeNode*> q;
        q.push(root);

        // BFS traversal to count frequencies
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            freq[node->val]++;

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }

        // Find maximum frequency
        int maxFreq = 0;
        for (auto& [val, count] : freq) {
            maxFreq = max(maxFreq, count);
        }

        // Collect all values with max frequency
        vector<int> result;
        for (auto& [val, count] : freq) {
            if (count == maxFreq) {
                result.push_back(val);
            }
        }

        return result;
    }
};

#include <functional>

class Solution2 {
public:
    vector<int> findMode(TreeNode* root) {
        vector<int> result;
        TreeNode* prev = nullptr;
        int currCount = 0, maxCount = 0;

        function<void(TreeNode*)> inorder = [&](TreeNode* node) {
            if (!node) return;

            inorder(node->left);

            // process current node
            if (prev && prev->val == node->val) {
                currCount++;
            } else {
                currCount = 1;
            }

            if (currCount > maxCount) {
                maxCount = currCount;
                result.clear();
                result.push_back(node->val);
            } else if (currCount == maxCount) {
                result.push_back(node->val);
            }

            prev = node;

            inorder(node->right);
        };

        inorder(root);
        return result;
    }
};
