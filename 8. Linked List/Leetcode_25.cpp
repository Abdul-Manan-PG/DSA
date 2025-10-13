// 25. Reverse Node in K-Groups

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
    ListNode* reverseList(ListNode* head) {
        ListNode* nextNode = nullptr;
        while (head != nullptr) {
            ListNode* temp = head->next;
            head->next = nextNode;
            nextNode = head;
            head = temp;
        }
        return nextNode;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1 || !head) return head;
        
        ListNode* prev_tail = nullptr;
        ListNode* r_ptr = head;
        
        while (r_ptr) {
            ListNode* r_head = r_ptr;
            ListNode* r_tail = r_ptr;
            
            // Move r_tail k-1 steps forward to find the end of the group
            for (int i = 1; i < k && r_tail; ++i) {
                r_tail = r_tail->next;
            }
            
            // If we couldn't form a full group of k, stop
            if (!r_tail) {
                break;
            }
            
            ListNode* next_group = r_tail->next;
            
            // Connect previous tail to the (future) new head of this group
            if (prev_tail) {
                prev_tail->next = r_tail;
            } else {
                head = r_tail;
            }
            
            // Isolate the group by setting r_tail->next to nullptr
            r_tail->next = nullptr;
            
            // Now reverse the group (r_head to r_tail)
            ListNode* new_head = reverseList(r_head);
            
            // The new tail of this group is the original r_head
            ListNode* new_tail = r_head;
            
            // Connect new tail to the next group
            new_tail->next = next_group;
            
            // Update prev_tail for the next iteration
            prev_tail = new_tail;
            
            // Move to the next group
            r_ptr = next_group;
        }
        
        return head;
    }
};
