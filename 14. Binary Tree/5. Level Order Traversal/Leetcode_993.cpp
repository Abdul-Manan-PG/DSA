// 993. Cousins in Binary Tree
// Problem:
// Given the root of a binary tree with unique values and the values of two different nodes x and y,
// determine whether the nodes corresponding to the values x and y are cousins.
// Two nodes are cousins if they are on the same depth but have different parents.
//
// Link: `https://leetcode.com/problems/cousins-in-binary-tree/`
//
// Constraints (LeetCode):
// - The number of nodes in the tree is in the range [1, 100].
// - 1 <= Node.val <= 100
//
// Expected Complexity:
// - BFS level-order: Time O(n), Space O(n)

#include <iostream>
#include <vector>
#include <queue>
#include <14. Binary Tree/TreeNode.h>
using namespace std;

class Solution1 {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        if (!root)
            return false;
        int order = 0;
        queue<pair<TreeNode*, TreeNode*>> q; // store {node, parent}
        int or1 = -1, or2 = -1;
        TreeNode* p1 = nullptr;
        TreeNode* p2 = nullptr;

        q.push({root, nullptr});
        q.push({nullptr, nullptr});

        while (!q.empty()) {
            auto [node, parent] = q.front();
            q.pop();

            if (!node) {
                if (q.empty()) {
                    break;
                } else {
                    q.push({nullptr, nullptr});
                    order++;
                    continue;
                }
            }

            if (node->val == x) {
                or1 = order;
                p1 = parent;
            } else if (node->val == y) {
                or2 = order;
                p2 = parent;
            }

            if (node->left)
                q.push({node->left, node});
            if (node->right)
                q.push({node->right, node});
        }

        if (or1 == -1 || or2 == -1) return false; // not found
        if (or1 != or2) return false;             // different levels
        if (p1 == p2) return false;               // same parent → siblings
        return true;                              // same level, different parents → cousins
    }
};

// Solution1 Complexity (BFS with parent tracking):
// - Time: O(n)
// - Space: O(n)


class Solution2 {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        if (!root)
            return false;
        int order = 0;
        queue<TreeNode*> q;
        int or1 = -1;
        int or2 = -1;
        q.push(root);
        q.push(NULL);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (!node) {
                if (q.empty()) {
                    break;
                } else {
                    q.push(NULL);
                    order++;
                    continue;
                }
            }

            // ✅ check sibling condition here
            if (node->left && node->right) {
                if ((node->left->val == x && node->right->val == y) ||
                    (node->left->val == y && node->right->val == x)) {
                    return false; // siblings, not cousins
                }
            }

            if (node->val == x) {
                or1 = order;
            } else if (node->val == y) {
                or2 = order;
            }

            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
        if (or1 <= 1 || or2 <= 1) return false;
        return or1 == or2;
    }
};

// Solution2 Complexity (BFS with sibling check):
// - Time: O(n)
// - Space: O(n)
