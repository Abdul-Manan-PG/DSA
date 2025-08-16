// 876. Middle of a Linked list

#include <iostream>
#include <vector>
#include <string>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
 
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