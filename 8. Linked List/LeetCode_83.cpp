// 83. Remove Duplicates from Sorted List
// Problem:
// Given the head of a sorted linked list, delete all duplicates such that each element appears only once.
// Return the linked list sorted as well.
//
// Link: `https://leetcode.com/problems/remove-duplicates-from-sorted-list/`
//
// Constraints (LeetCode):
// - The number of nodes in the list is in the range [0, 300]
// - -100 <= Node.val <= 100
//
// Expected Complexity:
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) return nullptr;

        ListNode* current = head;
        while (current != nullptr && current->next != nullptr) {
            if (current->val == current->next->val) {
                current->next = current->next->next;
            } else {
                current = current->next;
            }
        }
        return head;
    }
};
