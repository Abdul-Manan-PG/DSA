// 234. Palindrome Linked List
// Problem:
// Given the head of a singly linked list, return true if it is a palindrome or false otherwise.
//
// Link: `https://leetcode.com/problems/palindrome-linked-list/`
//
// Constraints (LeetCode):
// - The number of nodes in the list is in the range [1, 10^5].
// - 0 <= Node.val <= 9
//
// Expected Complexity (reverse second-half approach):
// - Time: O(n)
// - Space: O(1)

#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next) {
            fast = fast->next;
            if (fast->next) {
                slow = slow->next;
                fast = fast->next;
            }
        }
        ListNode* second_half = slow->next;
        ListNode* prev = nullptr;
        ListNode* curr = second_half;
        while (curr) {
            ListNode* next_temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next_temp;
        }
        ListNode* p1 = head;
        ListNode* p2 = prev;
        while (p2) {
            if (p1->val != p2->val) {
                return false;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        return true;
    }
};
