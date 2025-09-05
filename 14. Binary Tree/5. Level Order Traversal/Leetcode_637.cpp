// 637. Average of Levels in Binary Tree

#include <iostream>
#include <vector>
#include <queue>
#include <14. Binary Tree/TreeNode.h>
using namespace std;

class Solution
{
public:
    vector<double> averageOfLevels(TreeNode *root)
    {
        if (!root)
            return {};
        vector<double> ans;
        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);
        double sum = 0;
        int count = 0;
        while (q.size() > 0)
        {
            TreeNode *node = q.front();
            q.pop();
            if (!node)
            {
                sum /= count;
                ans.push_back(sum);
                sum = 0;
                count = 0;
                if (q.empty())
                {
                    break;
                }
                else
                {
                    q.push(NULL);
                    continue;
                }
            }
            sum += node->val;
            count++;
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
        return ans;
    }
};