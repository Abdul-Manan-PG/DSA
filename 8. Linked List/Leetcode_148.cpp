// 148. Sort List
// Problem:
// Given the head of a linked list, return the list after sorting it in ascending order.
//
// Link: `https://leetcode.com/problems/sort-list/`
//
// Constraints (LeetCode):
// - The number of nodes in the list is in the range [0, 5 * 10^4].
// - -10^5 <= Node.val <= 10^5
// - The list is not necessarily sorted initially.
//
// Expected Complexity (merge sort on linked list):
// - Time: O(n log n)
// - Space: O(log n) recursion stack

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

// Solution Complexity (merge sort):
// - Time: O(n log n)
// - Space: O(log n)

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* mid = slow->next;
        slow->next = nullptr;

        ListNode* left = sortList(head);
        ListNode* right = sortList(mid);
        return mergeTwoLists(left, right);
    }

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                tail->next = l1;
                l1 = l1->next;
            }
            else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        tail->next = l1 ? l1 : l2;
        return dummy.next;
    }
};