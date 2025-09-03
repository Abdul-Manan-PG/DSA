// GFG. Linked list to Binary Tree

#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Solution {
public:
    Node* linkedListToBinaryTree(NodeLL* head) {
        if (head == NULL) return NULL; // handle empty list

        vector<Node*> nodes;
        while (head != NULL) {
            Node* n = new Node(head->data); // allocation on heap
            nodes.push_back(n);
            head = head->next;
        }

        int size = nodes.size();
        for (int i = 0; i < size; i++) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            if (left < size) {
                nodes[i]->left = nodes[left];
            }
            if (right < size) {
                nodes[i]->right = nodes[right];
            }
        }
        return nodes[0];
    }
};
