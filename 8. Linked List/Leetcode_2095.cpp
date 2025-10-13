// 2095. Delete Middle node of Linked List

#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (!head || !head->next) return nullptr;

        ListNode* prev = nullptr;
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        if (prev) prev->next = slow->next;  // Remove middle node
        delete slow;  // Free memory

        return head;
    }
};