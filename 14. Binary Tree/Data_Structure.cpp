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
    
    // Destructor
    ~Node_bt() {}
    
    // Getter and Setter methods
    int getData() const { return data; }
    void setData(int val) { data = val; }
    
    Node_bt* getLeft() const { return left; }
    void setLeft(Node_bt* node) { left = node; }
    
    Node_bt* getRight() const { return right; }   // fixed here
    void setRight(Node_bt* node) { right = node; } // fixed here
    
    // Utility method to check if node is leaf
    bool isLeaf() const {
        return (left == nullptr && right == nullptr);
    }

    friend class Binary_Tree; // allow Binary_Tree to access private members
};

class Binary_Tree {
private:
    Node_bt* root;
    int ind;

    // Utility recursive build function
    Node_bt* buildTreeHelper(const vector<int>& preorder) {
        ind++;
        if (ind >= (int)preorder.size() || preorder[ind] == -1) return nullptr;

        Node_bt* rootNode = new Node_bt(preorder[ind]);
        rootNode->left = buildTreeHelper(preorder);
        rootNode->right = buildTreeHelper(preorder);

        return rootNode;
    }

    // Traversals
    void preorder(Node_bt* node) {
        if (!node) return;
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

    void inorder(Node_bt* node) {
        if (!node) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    void postorder(Node_bt* node) {
        if (!node) return;
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }

    int countNodes(Node_bt* node) {
        if (!node) return 0;
        return 1 + countNodes(node->left) + countNodes(node->right);
    }

    int height(Node_bt* node) {
        if (!node) return 0;
        return 1 + max(height(node->left), height(node->right));
    }

    bool search(Node_bt* node, int key) {
        if (!node) return false;
        if (node->data == key) return true;
        return search(node->left, key) || search(node->right, key);
    }

public:
    Binary_Tree() : root(nullptr), ind(-1) {}

    // Build tree from preorder with -1 as null marker
    void buildTree(const vector<int>& preorder) {
        ind = -1;
        root = buildTreeHelper(preorder);
    }

    // Traversal wrappers
    void preorderTraversal() { preorder(root); cout << endl; }
    void inorderTraversal() { inorder(root); cout << endl; }
    void postorderTraversal() { postorder(root); cout << endl; }

    // Other utilities
    int getNodeCount() { return countNodes(root); }
    int getHeight() { return height(root); }
    bool contains(int key) { return search(root, key); }
};

int main() {
    Binary_Tree bt;
    // Example: Preorder input with -1 as NULL
    // Tree:      1
    //           / \
    //          2   3
    //             / \
    //            4   5
    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    bt.buildTree(preorder);

    cout << "Preorder: ";
    bt.preorderTraversal();

    cout << "Inorder: ";
    bt.inorderTraversal();

    cout << "Postorder: ";
    bt.postorderTraversal();

    cout << "Node count: " << bt.getNodeCount() << endl;
    cout << "Height: " << bt.getHeight() << endl;
    cout << "Contains 4? " << (bt.contains(4) ? "Yes" : "No") << endl;
    cout << "Contains 6? " << (bt.contains(6) ? "Yes" : "No") << endl;

    return 0;
}
