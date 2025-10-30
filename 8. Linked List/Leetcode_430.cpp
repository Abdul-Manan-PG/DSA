// 430. Flatten a Multilevel Doubly Linked List

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

class Solution {
public:
    Node* flatten(Node* head) {
        if (!head) return nullptr;

        Node* curr = head;
        while (curr) {
            if (curr->child) {
                Node* child = flatten(curr->child);
                Node* next = curr->next;

                curr->next = child;
                child->prev = curr;
                curr->child = nullptr;

                Node* tail = child;
                while (tail->next) tail = tail->next;

                tail->next = next;
                if (next) next->prev = tail;
            }
            curr = curr->next;
        }
        return head;
    }
};
