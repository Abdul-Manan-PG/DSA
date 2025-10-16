// 25. Reverse Nodes in k-Group
// Problem:
// Given the head of a linked list, reverse the nodes of the list k at a time, and
// return the modified list. k is a positive integer and is less than or equal to
// the length of the linked list. If the number of nodes is not a multiple of k then
// the remaining nodes, in the end, should remain as is. You may not alter the values
// in the list's nodes, only nodes themselves may be changed.
//
// Link: `https://leetcode.com/problems/reverse-nodes-in-k-group/`
//
// Constraints (LeetCode):
// - The number of nodes n is in the range [0, 5000].
// - 0 <= Node.val <= 1000
// - 1 <= k <= n (when n > 0); behavior for n < k leaves remaining nodes unchanged
//
// Expected Complexity:
// - Time: O(n)
// - Space: O(1)
// Sample Test Cases:
// 1) Input: head = [1,2,3,4,5], k = 2
//    Output: [2,1,4,3,5]
// 2) Input: head = [1,2,3,4,5], k = 3
//    Output: [3,2,1,4,5]
// 3) Input: head = [1,2,3,4,5], k = 1
//    Output: [1,2,3,4,5]
// 4) Input: head = [], k = 2
//    Output: []

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

//
// Solution Complexity:
// - Time: O(n)
// - Space: O(1)
//