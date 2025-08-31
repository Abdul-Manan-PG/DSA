// GFG. Remove the half nodes(only child of a parent)

#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*Complete the function below
Node is as follows:
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

// Return the root of the modified tree after removing all the half nodes.
class Solution {
public:
    Node* RemoveHalfNodes(Node* root) {
        if (root == NULL) return NULL;

        // Recursively fix left and right subtrees
        root->left = RemoveHalfNodes(root->left);
        root->right = RemoveHalfNodes(root->right);

        // If this is a leaf node or full node, return it as is
        if (root->left != NULL && root->right != NULL) {
            return root;
        }

        // If this node has only left child, return left child
        if (root->left != NULL) {
            Node* newRoot = root->left;
            delete root;  // Optional: free memory if needed
            return newRoot;
        }

        // If this node has only right child, return right child
        if (root->right != NULL) {
            Node* newRoot = root->right;
            delete root;  // Optional: free memory if needed
            return newRoot;
        }

        // If this node is a leaf node (no children), return it
        return root;
    }
};
