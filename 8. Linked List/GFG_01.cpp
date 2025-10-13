// GFG. Add 1 to a Linked List Number

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