// 328. Odd Even Linked List
// Problem:
// Given the head of a singly linked list, group all the nodes with odd indices together followed by
// the nodes with even indices, and return the reordered list. The first node is considered odd.
//
// Link: `https://leetcode.com/problems/odd-even-linked-list/`
//
// Constraints (LeetCode):
// - n == number of nodes in the linked list
// - 0 <= n <= 10^4
// - -10^6 <= Node.val <= 10^6
//
// Expected Complexity:
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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;
        
        ListNode* oddHead = head;
        ListNode* evenHead = head->next;
        ListNode* oddTail = head;
        ListNode* evenTail = head->next;
        
        while (evenTail && evenTail->next) {
            ListNode* nextOdd = evenTail->next;
            oddTail->next = nextOdd;
            oddTail = nextOdd;
            evenTail->next = oddTail->next;
            evenTail = evenTail->next;
        }
        
        oddTail->next = evenHead;
        return head;
    }
};
