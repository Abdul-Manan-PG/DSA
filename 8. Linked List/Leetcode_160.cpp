// 160. Intersection of Two Linked Lists
// Problem:
// Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect.
// If the two linked lists have no intersection, return null.
//
// Link: `https://leetcode.com/problems/intersection-of-two-linked-lists/`
//
// Constraints (LeetCode):
// - The number of nodes of each list is in the range [0, 3 * 10^4].
// - -10^5 <= Node.val <= 10^5
// - 0 <= skipA < m, 0 <= skipB < n
//
// Expected Complexity (two-pointer switching):
// - Time: O(m + n)
// - Space: O(1)

#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Solution Complexity:
// - Time: O(m + n)
// - Space: O(1)

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