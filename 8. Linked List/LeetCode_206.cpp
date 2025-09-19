// 206. Reverse the Linked List

#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

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