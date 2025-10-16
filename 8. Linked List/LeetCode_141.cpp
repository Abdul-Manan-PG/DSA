// 141. Linked List Cycle
// Problem:
// Given head, the head of a linked list, determine if the linked list has a cycle in it.
//
// Link: `https://leetcode.com/problems/linked-list-cycle/`
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

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Solution Complexity:
// - Time: O(n)
// - Space: O(1)
class Solution {
public:
    bool hasCycle(ListNode* head) {
        if (!head)
            return false;

        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast && fast->next) {
            if (slow == fast)
                return true;
            slow = slow->next;
            fast = fast->next->next;
        }

        return false;
    }
};