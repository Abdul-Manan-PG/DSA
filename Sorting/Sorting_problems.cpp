#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// -----------------bubble sort function

void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n-1; i++) {
        bool swapped = false;
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

// int main() {
//     vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    
//     cout << "Original array: ";
//     for (int num : arr) {
//         cout << num << " ";
//     }
//     cout << endl;
    
//     bubbleSort(arr);
    
//     cout << "Sorted array: ";
//     for (int num : arr) {
//         cout << num << " ";
//     }
//     cout << endl;
//     return 0;
// }



// --------------------Selection Sorting 

void selectionSort(vector<int> &arr, bool desc = false) 
{
    for (int i = 0; i < arr.size() - 1; i++)
    {
        int target = i; // Index of min/max element
        for (int j = i + 1; j < arr.size(); j++) 
        {
            if (desc && arr[j] > arr[target]) 
            {
                target = j;
            } 
            else if (!desc && arr[j] < arr[target]) 
            {
                target = j;
            }
        }
        swap(arr[i], arr[target]);
    }
}

// int main() {
//     vector<int> arr = {64, 25, 12, 22, 11};
    
//     cout << "Original array: ";
//     for (int num : arr) cout << num << " ";
//     cout << endl;

//     // Ascending order (default)
//     selectionSort(arr);
//     cout << "Ascending order: ";
//     for (int num : arr) cout << num << " ";
//     cout << endl;

//     // Descending order
//     selectionSort(arr, true);
//     cout << "Descending order: ";
//     for (int num : arr) cout << num << " ";
//     cout << endl;

//     return 0;
// }



// -----------------Insertion sorting 

void insertionSort(vector<int> &arr, bool desc = false) {
    for (int i = 1; i < arr.size(); i++) {
        int key = arr[i];
        int j = i - 1;
        
        if (desc) {
            while (j >= 0 && arr[j] < key) {
                arr[j + 1] = arr[j];
                j--;
            }
        } else {
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }
        }
        arr[j + 1] = key;
    }
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6};
    
    cout << "Original array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    // Ascending order (default)
    insertionSort(arr);
    cout << "Ascending order: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    // Descending order
    insertionSort(arr, true);
    cout << "Descending order: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    return 0;
}


// ----------------- Leet code Problem no 147 -- Insertion sort List ---------------

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
        if (!head || !head->next) return head;
        
        ListNode* dummy = new ListNode(0); // dummy node to serve as sorted list's head
        ListNode* current = head; // current node to be inserted
        
        while (current) {
            ListNode* next = current->next; // store next node before insertion
            ListNode* prev = dummy; // start from dummy each time
            
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