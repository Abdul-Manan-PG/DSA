// 1373. Maximum Sum BST in Binary Tree

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

class Solution
{
public:
    struct Info
    {
        bool isBST;
        int sum;
        int minVal;
        int maxVal;
        Info(bool b, int s, int mi, int ma)
            : isBST(b), sum(s), minVal(mi), maxVal(ma) {}
    };
    int maxSum = 0;
    Info Helper(TreeNode *root)
    {
        if (!root)
            return Info(true, 0, INT_MAX, INT_MIN);

        auto left = Helper(root->left);
        auto right = Helper(root->right);

        if (left.isBST && right.isBST && root->val > left.maxVal &&
            root->val < right.minVal)
        {
            int sum = left.sum + right.sum + root->val;
            maxSum = std::max(maxSum, sum);
            return Info(true, sum, std::min(root->val, left.minVal),
                        std::max(root->val, right.maxVal));
        }
        return Info(false, 0, 0, 0);
    }

    int maxSumBST(TreeNode *root)
    {
        maxSum = 0;
        Helper(root);
        return maxSum;
    }
};
