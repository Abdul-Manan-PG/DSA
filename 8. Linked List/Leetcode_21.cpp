// 21. Merge Two Sorted Lists
// Problem:
// Merge two sorted linked lists and return it as a new sorted list.
// The new list should be made by splicing together the nodes of the first two lists.
//
// Link: `https://leetcode.com/problems/merge-two-sorted-lists/`
//
// Constraints (LeetCode):
// - The number of nodes in both lists is in the range [0, 50]
// - -100 <= Node.val <= 100
// - Both l1 and l2 are sorted in non-decreasing order.
//
// Expected Complexity:
// - Time: O(n + m)
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
// - Time: O(n + m)
// - Space: O(1)

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1) return list2;
        if (!list2) return list1;
        ListNode* head;
        ListNode* tail; 
        if (list1->val < list2->val){
            head = list1;
            list1 = list1->next;
        }
        else{
            head = list2;
            list2 = list2->next;
        }
        tail = head;
        while (list1 && list2){
            if (list1->val < list2->val){
                tail->next = list1;
                list1= list1->next;
                tail = tail->next;
            }
            else{
                tail->next = list2;
                list2 = list2->next;
                tail = tail->next;
            }
        }
        if (list1) tail->next = list1;
        if (list2) tail->next = list2;
        return head;
    }
};