// 147. Insertion sort list 

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