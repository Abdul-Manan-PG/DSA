// 206. Reverse Linked List
// Problem:
// Given the head of a singly linked list, reverse the list, and return the reversed list.
//
// Link: `https://leetcode.com/problems/reverse-linked-list/`
//
// Constraints (LeetCode):
// - The number of nodes in the list is in the range [0, 5000].
// - -5000 <= Node.val <= 5000
//
// Expected Complexity:
// - Iterative reversal: Time O(n), Space O(1)

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
    ListNode* reverseList(ListNode* head) {
        ListNode * nextNode = nullptr;
        while (head != nullptr){
            ListNode * temp = head->next;
            head->next = nextNode;
            nextNode = head;
            head = temp;
        }
        return nextNode;
    }
};