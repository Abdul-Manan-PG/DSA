// 61. Rotate the List

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || k <= 0) {
            return head;
        }
        
        // Compute the length of the list
        int len = 0;
        ListNode* p = head;
        while (p) {
            len++;
            p = p->next;
        }
        
        // Effective rotation steps
        k = k % len;
        if (k == 0) {
            return head;
        }
        
        // Find the (len - k)-th node (0-based index: len - k - 1 steps from head)
        ListNode* slow = head;
        for (int i = 0; i < len - k - 1; ++i) {
            slow = slow->next;
        }
        
        // New head is the next node after slow
        ListNode* new_head = slow->next;
        
        // Detach the tail
        slow->next = nullptr;
        
        // Find the end of the new list and connect to original head
        ListNode* last = new_head;
        while (last->next) {
            last = last->next;
        }
        last->next = head;
        
        return new_head;
    }
};