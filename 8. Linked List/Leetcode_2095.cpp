// 2095. Delete the Middle Node of a Linked List
// Problem:
// You are given the head of a linked list. Delete the middle node, and return the head of the modified list.
// If there are two middle nodes, delete the second middle node.
//
// Link: `https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/`
//
// Constraints (LeetCode):
// - The number of nodes in the list is in the range [1, 10^5].
// - 1 <= Node.val <= 10^5
//
// Expected Complexity:
// - Time: O(n)
// - Space: O(1)

#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Solution Complexity:
// - Time: O(n)
// - Space: O(1)

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (!head || !head->next) return nullptr;

        ListNode* prev = nullptr;
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        if (prev) prev->next = slow->next;  // Remove middle node
        delete slow;  // Free memory

        return head;
    }
};