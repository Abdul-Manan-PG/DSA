// 1008. Contruct BST from PreOrder Traversal

#include <iostream>
#include <vector>
#include <stack>
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

class Solution1
{
public:
    TreeNode *helper(vector<int> &preorder, int &i, int bound)
    {
        if (i >= preorder.size() || preorder[i] >= bound)
        {
            return NULL;
        }

        TreeNode *root = new TreeNode(preorder[i++]);

        root->left = helper(preorder, i, root->val);
        root->right = helper(preorder, i, bound);

        return root;
    }

    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        int i = 0;
        return helper(preorder, i, INT_MAX);
    }
};

class Solution2
{
public:
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        if (preorder.empty())
            return nullptr;

        TreeNode *root = new TreeNode(preorder[0]);
        stack<TreeNode*> st;
        st.push(root);

        for (int i = 1; i < preorder.size(); ++i)
        {
            TreeNode *node = new TreeNode(preorder[i]);

            if (preorder[i] < st.top()->val)
            {
                // It must be the left child of the top node
                st.top()->left = node;
            }
            else
            {
                TreeNode *parent = nullptr;
                // Find the parent to which this node is the right child
                while (!st.empty() && preorder[i] > st.top()->val)
                {
                    parent = st.top();
                    st.pop();
                }
                parent->right = node;
            }
            st.push(node);
        }

        return root;
    }
};