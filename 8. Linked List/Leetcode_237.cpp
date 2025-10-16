// 237. Delete Node in a Linked List
// Problem:
// There is a singly-linked list head and we want to delete a node in it.
// You are given the node to be deleted (not the head). Delete the node.
// Note: The node to be deleted is not a tail node.
//
// Link: `https://leetcode.com/problems/delete-node-in-a-linked-list/`
//
// Constraints (LeetCode):
// - The number of nodes in the list is in the range [2, 1000].
// - -1000 <= Node.val <= 1000
// - The value of each node in the list is unique.
// - The node to be deleted is in the list and is not a tail node.
//
// Expected Complexity:
// - Time: O(1)
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

// Solution Complexity:
// - Time: O(1)
// - Space: O(1)

class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* temp = node->next;
        node->val=node->next->val;
        node->next=node->next->next;
        delete temp;
    }
};