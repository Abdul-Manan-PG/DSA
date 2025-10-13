// 19. Remove N-th node from the End of Linked List

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head) return nullptr;
        
        // Create a dummy node to handle edge cases (e.g., removing the head)
        ListNode* dummy = new ListNode(0, head);
        ListNode* slow = dummy;
        ListNode* fast = head;
        
        // Move fast n steps ahead
        for (int i = 0; i < n; i++) {
            if (!fast) return nullptr; // Invalid n, but per problem constraints, shouldn't happen
            fast = fast->next;
        }
        
        // Move both slow and fast until fast reaches the end
        while (fast) {
            slow = slow->next;
            fast = fast->next;
        }
        
        // Now slow is pointing to the node before the one to remove
        slow->next = slow->next->next;
        
        return dummy->next;
    }
};
