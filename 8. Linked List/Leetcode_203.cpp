// 203. Remove Linked List Elements
// Problem:
// Given the head of a linked list and an integer val, remove all the nodes of the linked list
// that have Node.val == val, and return the new head.
//
// Link: `https://leetcode.com/problems/remove-linked-list-elements/`
//
// Constraints (LeetCode):
// - The number of nodes in the list is in the range [0, 10^4].
// - -10^5 <= Node.val <= 10^5
// - 0 <= val <= 10^5
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* pre = nullptr;
        ListNode* r_ptr = head;
        while (r_ptr){
            if (r_ptr->val==val){
                if (pre){
                    pre->next = r_ptr->next;
                    delete r_ptr;
                    r_ptr = pre->next;
                }
                else{
                    head = head->next;
                    delete r_ptr;
                    r_ptr = head;
                }
            }
            else{
                pre = r_ptr;
                r_ptr = r_ptr->next;
            }
        }
        return head;
    }
};