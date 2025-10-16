// 142. Linked List Cycle II
// Problem:
// Given the head of a linked list, return the node where the cycle begins.
// If there is no cycle, return null.
//
// Link: `https://leetcode.com/problems/linked-list-cycle-ii/`
//
// Constraints (LeetCode):
// - The number of nodes in the list is in the range [0, 10^4].
// - -10^5 <= Node.val <= 10^5
//
// Expected Complexity (Floyd's Tortoise and Hare):
// - Time: O(n)
// - Space: O(1)

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

// Solution Complexity:
// - Time: O(n)
// - Space: O(1)

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next) return NULL;

        ListNode *slow = head;
        ListNode *fast = head;

        // Step 1: Detect if a cycle exists
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                // Step 2: Find the start of the cycle
                slow = head;
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;  // starting node of the cycle
            }
        }

        return NULL;  // no cycle
    }
};