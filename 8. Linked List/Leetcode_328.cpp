// 328. Odd Even Linked List

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
