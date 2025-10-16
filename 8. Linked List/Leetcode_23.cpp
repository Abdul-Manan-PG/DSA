// 23. Merge k Sorted Lists
// Problem:
// You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
// Merge all the linked-lists into one sorted linked-list and return it.
//
// Link: `https://leetcode.com/problems/merge-k-sorted-lists/`
//
// Constraints (LeetCode):
// - k == lists.length
// - 0 <= k <= 10^4
// - 0 <= lists[i].length <= 500
// - -10^4 <= lists[i][j] <= 10^4
//
// Expected Complexity (pairwise merge shown here):
// - Time: O(N*k) where N is total number of nodes
// - Space: O(1) extra (excluding recursion for helper)

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Solution Complexity (pairwise merge):
// - Time: O(N*k)
// - Space: O(1)

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (!list1)
            return list2;
        if (!list2)
            return list1;
        ListNode *head;
        ListNode *tail;
        if (list1->val < list2->val)
        {
            head = list1;
            list1 = list1->next;
        }
        else
        {
            head = list2;
            list2 = list2->next;
        }
        tail = head;
        while (list1 && list2)
        {
            if (list1->val < list2->val)
            {
                tail->next = list1;
                list1 = list1->next;
                tail = tail->next;
            }
            else
            {
                tail->next = list2;
                list2 = list2->next;
                tail = tail->next;
            }
        }
        if (list1)
            tail->next = list1;
        if (list2)
            tail->next = list2;
        return head;
    }
    ListNode *mergeKLists(vector<ListNode *> &list)
    {
        if (list.size() == 0)
            return nullptr;
        if (list.size() == 1)
            return list[0];
        ListNode *node = nullptr;
        for (int i = 0; i < list.size(); i++)
        {
            node = mergeTwoLists(node, list[i]);
        }
        return node;
    }
};