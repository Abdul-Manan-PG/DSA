// 92. Reverse the Linked List 2

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

class Solution
{
public:
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        if (!head || left >= right)
            return head;

        ListNode *dummy =
            new ListNode(0, head); // Dummy node simplifies edge cases
        ListNode *prev = dummy;

        // Move prev to the node before 'left'
        for (int i = 1; i < left; ++i)
        {
            prev = prev->next;
        }

        // Start of the sublist to reverse
        ListNode *curr = prev->next;
        ListNode *nextNode = nullptr;

        // Reverse the sublist from left to right
        for (int i = left; i <= right && curr; ++i)
        {
            ListNode *temp = curr->next;
            curr->next = nextNode;
            nextNode = curr;
            curr = temp;
        }

        // Connect back: prev->next should point to the new head of reversed
        // sublist
        prev->next->next =
            curr; // Original left's next points to the node after right
        prev->next =
            nextNode; // prev points to the new head of reversed sublist

        return dummy->next; // Return the real head
    }
};