// GFG. Two trees are mirror of each other 


#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
  public:
    bool areMirror(Node* a, Node* b) {
        // Your code here
        // Case 1: both are null -> trees are same
        if (a == nullptr && b == nullptr) return true;

        // Case 2: one is null and other is not -> trees are different
        else if (a == nullptr || b == nullptr) return false;

        // Case 3: values mismatch -> trees are different
        else if (a->val != b->val) return false;
        
        // Case 4: check subtrees recursively
        return areMirror(a->left, b->right) && areMirror(a->right, b->left);
    }
};