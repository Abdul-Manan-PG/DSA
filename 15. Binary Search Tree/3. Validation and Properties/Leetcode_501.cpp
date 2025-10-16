// 501. Find Mode in Binary Search Tree
// Problem:
// Given the root of a binary search tree (BST) with duplicates allowed, return all the mode(s)
// (i.e., the most frequently occurred element) in the given BST.
//
// Link: `https://leetcode.com/problems/find-mode-in-binary-search-tree/`
//
// Constraints (LeetCode):
// - The number of nodes in the tree is in the range [1, 10^4].
// - -10^5 <= Node.val <= 10^5
//
// Expected Complexity:
// - BFS/HashMap: Time O(n), Space O(n)
// - Inorder single pass: Time O(n), Space O(h) recursion

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

// Solution1 Complexity (BFS + HashMap):
// - Time: O(n)
// - Space: O(n)

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

// Solution2 Complexity (Inorder traversal with counters):
// - Time: O(n)
// - Space: O(h)

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
