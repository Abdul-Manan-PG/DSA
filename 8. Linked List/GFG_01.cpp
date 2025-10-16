// GFG: Add 1 to a Linked List Number
// Problem:
// Given a non-negative number represented as a linked list of digits. The head node contains the most significant digit.
// Add 1 to the number and return the resulting list.
//
// Link: `https://www.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1`
//
// Constraints (GFG typical):
// - 1 <= N <= 10^5
// - 0 <= Node.data <= 9
//
// Expected Complexity (recursive carry-propagation):
// - Time: O(n)
// - Space: O(n) recursion

#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int x){
        data = x;
        next= NULL;
    }
};

// Solution Complexity:
// - Time: O(n)
// - Space: O(n)

class Solution {
  public:
    int remainder(Node* head){
        int rem = 1;
        if (head->next){
            rem = remainder(head->next);
        }
        head->data = head->data+rem;
        rem = head->data / 10;
        head->data  = head->data % 10;
        return rem;
    }
    Node* addOne(Node* head) {
        // Your Code here
        int rem = remainder(head);
        if (rem == 0) return head;
        Node * dummy = new Node(rem);
        dummy->next = head;
        // return head of list after adding one
        return dummy;
    }
};