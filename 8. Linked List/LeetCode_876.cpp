// 876. Middle of the Linked List
// Problem:
// Given the head of a singly linked list, return the middle node of the linked list.
// If there are two middle nodes, return the second middle node.
//
// Link: `https://leetcode.com/problems/middle-of-the-linked-list/`
//
// Constraints (LeetCode):
// - The number of nodes in the list is in the range [1, 100].
// - 1 <= Node.val <= 100
//
// Expected Complexity:
// - Two-pass count or fast/slow pointers: Time O(n)
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
    ListNode* middleNode(ListNode* head) {
        ListNode * current = head;
        int size = 0;
        while (current != nullptr){
            size++;
            current = current->next;
        }
        for (int i = 0; i < size / 2; i++){
            head = head->next;
        }
        return head;
    }
};