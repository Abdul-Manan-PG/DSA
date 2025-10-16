// 147. Insertion sort list 
// Problem:
// Given the head of a singly linked list, sort the list in ascending order using
// the insertion sort algorithm and return the head of the sorted list.
//
// Link: `https://leetcode.com/problems/insertion-sort-list/`
//
// Constraints (LeetCode):
// - The number of nodes n is in the range [1, 5 * 10^4].
// - -5000 <= Node.val <= 5000
// - The list may contain duplicate values.
//
// Expected Complexity:
// - Time: O(n^2) in the worst case (standard insertion sort on linked list)
// - Space: O(1) extra space
//
// Sample Test Cases:
// 1) Input: head = [-1, 5, 3, 4, 0]
//    Output: [-1, 0, 3, 4, 5]
// 2) Input: head = [4, 2, 1, 3]
//    Output: [1, 2, 3, 4]
// 3) Input: head = []
//    Output: []
// 4) Input: head = [1]
//    Output: [1]
// 5) Input: head = [1,1,1]
//    Output: [1,1,1]

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
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next)
            return head;

        ListNode* dummy =
            new ListNode(0);      // dummy node to serve as sorted list's head
        ListNode* current = head; // current node to be inserted

        while (current) {
            ListNode* next = current->next; // store next node before insertion
            ListNode* prev = dummy;         // start from dummy each time

            // find the correct position to insert current node
            while (prev->next && prev->next->val < current->val) {
                prev = prev->next;
            }

            // insert current node after prev
            current->next = prev->next;
            prev->next = current;

            // move to next node
            current = next;
        }

        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};

// Function to print the linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// Function to create a linked list from an array
ListNode* createList(int arr[], int n) {
    if (n == 0) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    for (int i = 1; i < n; i++) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

int main() {
    int arr[] = {-1, 5, 3, 4, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    ListNode* head = createList(arr, n);
    
    cout << "Original list: ";
    printList(head);
    
    Solution solution;
    ListNode* sortedHead = solution.insertionSortList(head);
    
    cout << "Sorted list: ";
    printList(sortedHead);
    
    return 0;
}

// Solution Complexity:
// - Time: O(n^2)
// - Space: O(1)
//