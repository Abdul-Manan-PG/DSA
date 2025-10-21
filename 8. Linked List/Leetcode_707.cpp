/**
 * LeetCode 707 — Design a Linked List
 *
 * Description:
 * Implement a singly linked list with the following operations:
 *  - get(index): Return the value of the index-th node in the linked list.
 *                  If the index is invalid, return -1.
 *  - addAtHead(val): Insert a node of value val before the first element of the linked list.
 *                    After the insertion, the new node will be the first node of the linked list.
 *  - addAtTail(val): Append a node of value val to the last element of the linked list.
 *  - addAtIndex(index, val): Insert a node of value val before the index-th node in the linked list.
 *                            If index equals the length of the list, the node will be appended to the end.
 *                            If index is greater than the length, the node will not be inserted.
 *                            If index is negative, the node will be inserted at the head.
 *  - deleteAtIndex(index): Delete the index-th node in the linked list, if the index is valid.
 *
 * Behavior notes:
 *  - Indices are zero-based (head has index 0).
 *  - get returns -1 when index is out of bounds.
 *  - addAtIndex with index == size appends at tail.
 *  - addAtIndex with index > size does nothing.
 *  - addAtIndex with index < 0 inserts at head (treat index as 0).
 *  - deleteAtIndex with invalid index does nothing.
 *
 * Typical time/space characteristics for a singly linked list implementation:
 *  - get(index): O(n) time, O(1) extra space
 *  - addAtHead(val): O(1) time, O(1) extra space
 *  - addAtTail(val): O(1) time if tail pointer maintained, otherwise O(n)
 *  - addAtIndex(index, val): O(n) time to locate insertion point, O(1) extra space
 *  - deleteAtIndex(index): O(n) time to locate predecessor, O(1) extra space
 *
 * Constraints (as in the LeetCode problem statement):
 *  - All values and indices are integers.
 *  - 0 <= val <= 1000
 *  - -1000 <= index <= 1000  (index may be negative in some calls; negative is treated as insert at head)
 *  - At most 2000 calls will be made to get, addAtHead, addAtTail, addAtIndex and deleteAtIndex.
 *
 * Usage example (semantics):
 *  MyLinkedList* obj = new MyLinkedList();
 *  obj->addAtHead(1);
 *  obj->addAtTail(3);
 *  obj->addAtIndex(1, 2);   // linked list becomes 1->2->3
 *  int param_1 = obj->get(1); // returns 2
 *  obj->deleteAtIndex(1);    // now the linked list is 1->3
 *
 */



#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct node {
    int val;
    node* next;
    node(int x) {
        val = x;
        next = nullptr;
    }
};

class MyLinkedList {
private:
    node* head;
    node* tail;

public:
    MyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    int get(int index) {
        int ind = 0;
        node* ptr = head;
        while (ptr) {
            if (ind == index)
                return ptr->val;
            ptr = ptr->next;
            ind++;
        }
        return -1; // Index out of bounds
    }

    void addAtHead(int val) {
        node* newNode = new node(val);
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    void addAtTail(int val) {
        node* newNode = new node(val);
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void addAtIndex(int index, int val) {
        if (index <= 0) {
            addAtHead(val);
            return;
        }
        
        node* r_ptr = head;
        int ind = 0;

        while (ind < index - 1 && r_ptr) {
            r_ptr = r_ptr->next;
            ind++;
        }

        if (!r_ptr) {
            return; // Index is greater than the size of the list
        }

        node* newNode = new node(val);
        newNode->next = r_ptr->next;
        r_ptr->next = newNode;

        if (newNode->next == nullptr) {
            tail = newNode; // Update tail if we added at the end
        }
    }

    void deleteAtIndex(int index) {
        if (index < 0) return; // Invalid index

        if (index == 0) {
            if (head) {
                node* temp = head;
                head = head->next;
                delete temp;
                if (!head) {
                    tail = nullptr; // List is now empty
                }
            }
            return;
        }

        node* pre = head;
        int ind = 0;

        while (ind < index - 1 && pre) {
            pre = pre->next;
            ind++;
        }

        if (!pre || !pre->next) {
            return; // Index is out of bounds
        }

        node* temp = pre->next;
        pre->next = pre->next->next;
        delete temp;

        if (!pre->next) {
            tail = pre; // Update tail if we deleted the last node
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
