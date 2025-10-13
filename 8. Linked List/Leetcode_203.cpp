// 203. Remove Linked List Elements

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