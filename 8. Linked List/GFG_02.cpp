// GFG. Reverse the k group of node in the linked list


#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct node{
    int val;
    node* next;
    node(int x){
        val = x;
        next = NULL;
    }
};

class Solution {
public:
    node* reverse(node* head, node* tail) {
        node* prev = tail;
        while (head != tail) {
            node* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }

    node* reverseKGroup(node* head, int k) {
        node* curr = head;
        node* prevGroupTail = NULL;

        while (curr) {
            node* groupStart = curr;
            node* ptr = curr;

            // move ptr k steps ahead OR until NULL (don't break early)
            for (int i = 0; i < k && ptr; i++) {
                ptr = ptr->next;
            }

            // reverse even if fewer than k nodes remain
            node* newHead = reverse(curr, ptr);

            if (!prevGroupTail)
                head = newHead;
            else
                prevGroupTail->next = newHead;

            prevGroupTail = groupStart;
            curr = ptr;
        }

        return head;
    }
};
