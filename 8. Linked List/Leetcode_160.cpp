// 160. Intersection of Two Linked Lists

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return nullptr;

        ListNode* ptrA = headA;
        ListNode* ptrB = headB;

        // Traverse both lists, switching heads when reaching the end
        while (ptrA != ptrB) {
            ptrA = ptrA ? ptrA->next : headB;
            ptrB = ptrB ? ptrB->next : headA;
        }

        // Either both are nullptr (no intersection) or at intersection node
        return ptrA;
    }
};