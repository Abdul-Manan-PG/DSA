#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Node_bt {
private:
    int data;
    Node_bt* left;
    Node_bt* right;

public:
    // Default constructor
    Node_bt() : data(0), left(nullptr), right(nullptr) {}
    
    // Parameterized constructor
    Node_bt(int val) : data(val), left(nullptr), right(nullptr) {}
    
    // Destructor (optional but recommended for proper cleanup)
    ~Node_bt() {}
    
    // Getter and Setter methods (recommended for encapsulation)
    int getData() const { return data; }
    void setData(int val) { data = val; }
    
    Node_bt* getLeft() const { return left; }
    void setLeft(Node_bt* node) { left = node; }
    
    Node_bt* getRight() const { return left; }
    void setRight(Node_bt* node) { right = node; }
    
    // Utility method to check if node is leaf
    bool isLeaf() const {
        return (left == nullptr && right == nullptr);
    }
};

class Binary_Tree {
public:
    static int ind = -1;
    Node_bt* buildTree(vector<int> preorder)
    {
        ind++;

        if (preorder[ind] == -1) return Null;

        Node_bt* rootNode = new Node_bt(preorder[ind]);
        rootNode->left = buildTree(preorder);
        rootNode->right = buildTree(preorder);

        return rootNode;
    }
private:
    Node_bt* root;
};