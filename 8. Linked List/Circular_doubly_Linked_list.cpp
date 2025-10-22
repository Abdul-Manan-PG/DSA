// Implementation of circular doubly linked list

#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct node
{
    int val;
    node *pre;
    node *next;
    node(int x)
    {
        val = x;
        pre = nullptr;
        next = nullptr;
    }
};

class circularDoublyLinkedList
{
private:
    node *tail;

public:
    circularDoublyLinkedList()
    {
        tail = nullptr;
    }

    ~circularDoublyLinkedList()
    {
        if (!tail)
            return;
        node *current = tail->next; // Start from head
        while (current != tail)
        {
            node *temp = current;
            current = current->next;
            delete temp;
        }
        delete tail;
        tail = nullptr;
    }

    void insertAtHead(int val)
    {
        node *newNode = new node(val);
        if (!tail)
        {
            tail = newNode;
            tail->next = tail;
            tail->pre = tail;
        }
        else
        {
            newNode->next = tail->next;
            tail->next->pre = newNode;
            newNode->pre = tail;
            tail->next = newNode;
        }
    }

    void insertAtTail(int val)
    {
        node *newNode = new node(val);
        if (!tail)
        {
            tail = newNode;
            tail->next = tail;
            tail->pre = tail;
        }
        else
        {
            newNode->next = tail->next;
            tail->next->pre = newNode;
            newNode->pre = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void insert(int val, int index)
    {
        if (index == 0)
        {
            insertAtHead(val);
            return;
        }
        if (!tail)
        {
            // If list is empty, insert at head (which is also tail)
            insertAtHead(val);
            return;
        }
        int count = 0;
        node *r_ptr = tail->next; // Start from head
        while (count < index - 1 && r_ptr != tail)
        {
            count++;
            r_ptr = r_ptr->next;
        }
        if (count == index - 1 && r_ptr != tail)
        {
            node *newNode = new node(val);
            newNode->pre = r_ptr;
            newNode->next = r_ptr->next;
            r_ptr->next->pre = newNode;
            r_ptr->next = newNode;
        }
        else
        {
            // If index is out of bounds or at the end, insert at tail
            insertAtTail(val);
        }
    }

    // Additional helper methods for completeness (optional, but useful for testing)
    void printList()
    {
        if (!tail)
        {
            cout << "List is empty" << endl;
            return;
        }
        node *temp = tail->next;
        do
        {
            cout << temp->val << " ";
            temp = temp->next;
        } while (temp != tail->next);
        cout << endl;
    }

    int getSize()
    {
        if (!tail)
            return 0;
        int size = 1;
        node *temp = tail->next;
        while (temp != tail)
        {
            size++;
            temp = temp->next;
        }
        return size;
    }

    bool deleteHead()
    {
        if (!tail)
            return false;
        if (tail->next == tail)
        {
            delete tail;
            tail = nullptr;
            return true;
        }
        node *temp = tail->next;
        tail->next = tail->next->next;
        tail->next->pre = tail;
        delete temp;
        return true;
    }

    bool deleteTail()
    {
        if (!tail)
            return false;
        if (tail->next == tail)
        {
            delete tail;
            tail = nullptr;
            return true;
        }
        node *temp = tail;
        tail = tail->pre;
        tail->next = temp->next;
        temp->next->pre = tail;
        delete temp;
        return true;
    }

    bool deleteIndex(int index)
    {
        if (!tail)
            return false;
        int size = getSize();
        if (index < 0 || index >= size)
            return false;
        if (index == 0)
        {
            return deleteHead();
        }
        if (index == size - 1)
        {
            return deleteTail();
        }
        // Traverse to the node at index
        node *current = tail->next; // Start from head
        for (int i = 0; i < index; i++)
        {
            current = current->next;
        }
        // Now current is the node to delete
        current->pre->next = current->next;
        current->next->pre = current->pre;
        delete current;
        return true;
    }
};

int main()
{
    circularDoublyLinkedList list;

    // Test insertions
    cout << "Inserting at head: 10, 20, 30" << endl;
    list.insertAtHead(10);
    list.insertAtHead(20);
    list.insertAtHead(30);
    list.printList(); // Should print: 30 20 10
    cout << "Size: " << list.getSize() << endl; // 3

    cout << "\nInserting at tail: 40, 50" << endl;
    list.insertAtTail(40);
    list.insertAtTail(50);
    list.printList(); // Should print: 30 20 10 40 50
    cout << "Size: " << list.getSize() << endl; // 5

    cout << "\nInserting 25 at index 2" << endl;
    list.insert(25, 2);
    list.printList(); // Should print: 30 20 25 10 40 50
    cout << "Size: " << list.getSize() << endl; // 6

    cout << "\nInserting 60 at index 10 (out of bounds, should insert at tail)" << endl;
    list.insert(60, 10);
    list.printList(); // Should print: 30 20 25 10 40 50 60
    cout << "Size: " << list.getSize() << endl; // 7

    // Test deletions
    cout << "\nDeleting head" << endl;
    list.deleteHead();
    list.printList(); // Should print: 20 25 10 40 50 60
    cout << "Size: " << list.getSize() << endl; // 6

    cout << "\nDeleting tail" << endl;
    list.deleteTail();
    list.printList(); // Should print: 20 25 10 40 50
    cout << "Size: " << list.getSize() << endl; // 5

    cout << "\nDeleting at index 2" << endl;
    list.deleteIndex(2);
    list.printList(); // Should print: 20 25 40 50
    cout << "Size: " << list.getSize() << endl; // 4

    cout << "\nDeleting at index 0 (head)" << endl;
    list.deleteIndex(0);
    list.printList(); // Should print: 25 40 50
    cout << "Size: " << list.getSize() << endl; // 3

    cout << "\nDeleting at index 2 (tail)" << endl;
    list.deleteIndex(2);
    list.printList(); // Should print: 25 40
    cout << "Size: " << list.getSize() << endl; // 2

    cout << "\nDeleting at index 1" << endl;
    list.deleteIndex(1);
    list.printList(); // Should print: 25
    cout << "Size: " << list.getSize() << endl; // 1

    cout << "\nDeleting head (last element)" << endl;
    list.deleteHead();
    list.printList(); // Should print: List is empty
    cout << "Size: " << list.getSize() << endl; // 0

    // Test edge cases
    cout << "\nTrying to delete from empty list" << endl;
    cout << "Delete head: " << (list.deleteHead() ? "Success" : "Failed") << endl;
    cout << "Delete tail: " << (list.deleteTail() ? "Success" : "Failed") << endl;
    cout << "Delete index 0: " << (list.deleteIndex(0) ? "Success" : "Failed") << endl;

    return 0;
}
