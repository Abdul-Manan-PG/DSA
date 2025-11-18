// 143. Reorder the list

#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x){
        val = x;
        next = NULL;
    }
};

class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next || !head->next->next) return;
        
        // Find the last node
        ListNode* last = head;
        ListNode* prev = head;
        while (last->next) {
            prev = last;
            last = last->next;
        }
        prev->next = nullptr;
        last->next = head->next;
        head->next = last;
        reorderList(last->next);
    }
};

