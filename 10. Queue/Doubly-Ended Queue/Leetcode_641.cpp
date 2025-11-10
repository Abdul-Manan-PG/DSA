// 641. Design Circular Deque

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Solution 1: Using Circular Array

class MyCircularDeque
{
    int *arr;
    int front;
    int rear;
    int size;

public:
    MyCircularDeque(int k)
    {
        size = k;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    ~MyCircularDeque()
    {
        delete[] arr;
    }

    bool insertFront(int value)
    {
        if (isFull())
            return false;
        if (isEmpty())
        {
            front = 0;
            rear = 0;
            arr[rear] = value;
            return true;
        }
        front = (front - 1 + size) % size;
        arr[front] = value;
        return true;
    }

    bool insertLast(int value)
    {
        if (isFull())
            return false;
        if (isEmpty())
        {
            front = 0;
            rear = 0;
            arr[rear] = value;
            return true;
        }
        rear = (rear + 1) % size;
        arr[rear] = value;
        return true;
    }

    bool deleteFront()
    {
        if (isEmpty())
            return false;
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % size;
        }
        return true;
    }

    bool deleteLast()
    {
        if (isEmpty())
            return false;
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            rear = (rear - 1 + size) % size;
        }
        return true;
    }

    int getFront()
    {
        if (!isEmpty())
            return arr[front];
        return -1;
    }

    int getRear()
    {
        if (!isEmpty())
            return arr[rear];
        return -1;
    }

    bool isEmpty()
    {
        return front == -1;
    }

    bool isFull()
    {
        return (front == (rear + 1) % size);
    }
};

// Example usage
// int main()
// {
//     MyCircularDeque deque(3);
//     cout << deque.insertLast(1) << endl;  // return true
//     cout << deque.insertLast(2) << endl;  // return true
//     cout << deque.insertFront(3) << endl; // return true
//     cout << deque.insertFront(4) << endl; // return false, the queue is full
//     cout << deque.getRear() << endl;      // return 2
//     cout << deque.isFull() << endl;       // return true
//     cout << deque.deleteLast() << endl;   // return true
//     cout << deque.insertFront(4) << endl; // return true
//     cout << deque.getFront() << endl;     // return 4
//     return 0;
// }

// Solution 2: Using Singly Circular-Linked List

class node
{
public:
    int val;
    node *next;
    node(int value)
    {
        val = value;
        next = nullptr;
    }
    node(int value, node *ptr)
    {
        val = value;
        next = ptr;
    }
};

class MyCircularDeque2
{
    node *tail;
    int capacity;
    int elements;

public:
    MyCircularDeque2(int k)
    {
        capacity = k;
        elements = 0;
        tail = nullptr;
    }

    ~MyCircularDeque2()
    {
        while (!isEmpty())
        {
            deleteFront(); // Reuse deleteFront to clean up
        }
    }

    bool insertFront(int value)
    {
        if (isFull())
            return false;
        if (isEmpty())
        {
            elements++;
            tail = new node(value);
            tail->next = tail;
            return true;
        }
        elements++;
        node *newNode = new node(value);
        newNode->next = tail->next;
        tail->next = newNode;
        return true;
    }

    bool insertLast(int value)
    {
        if (isFull())
            return false;
        if (isEmpty())
        {
            elements++;
            tail = new node(value);
            tail->next = tail;
            return true;
        }
        elements++;
        tail->next = new node(value, tail->next);
        tail = tail->next;
        return true;
    }

    bool deleteFront()
    {
        if (isEmpty())
            return false;
        if (tail == tail->next)
        {
            elements = 0;
            delete tail;
            tail = nullptr;
            return true;
        }
        elements--;
        node *temp = tail->next;
        tail->next = tail->next->next;
        delete temp;
        return true;
    }

    bool deleteLast()
    {
        if (isEmpty())
            return false;
        if (tail == tail->next)
        {
            elements = 0;
            delete tail;
            tail = nullptr;
            return true;
        }
        elements--;
        // Find the node before tail
        node *prev = tail->next;
        while (prev->next != tail)
        {
            prev = prev->next;
        }
        prev->next = tail->next;
        delete tail;
        tail = prev;
        return true;
    }

    int getFront()
    {
        if (!isEmpty())
            return tail->next->val;
        return -1;
    }

    int getRear()
    {
        if (!isEmpty())
            return tail->val;
        return -1;
    }

    bool isEmpty()
    {
        return elements == 0;
    }

    bool isFull()
    {
        return elements == capacity;
    }
};

// int main()
// {
//     MyCircularDeque2 deque(3);
//     cout << deque.insertLast(1) << endl;  // return true
//     cout << deque.insertLast(2) << endl;  // return true
//     cout << deque.insertFront(3) << endl; // return true
//     cout << deque.insertFront(4) << endl; // return false, the queue is full
//     cout << deque.getRear() << endl;      // return 2
//     cout << deque.isFull() << endl;       // return true
//     cout << deque.deleteLast() << endl;   // return true
//     cout << deque.insertFront(4) << endl; // return true
//     cout << deque.getFront() << endl;     // return 4
//     return 0;
// }



// Solution 3: with circular doubly-linked list

struct Node
{
    int val;
    Node *pre;
    Node *next;
    Node(int x)
    {
        val = x;
        pre = nullptr;
        next = nullptr;
    }
};

class circularDoublyLinkedList
{
public:
    Node *tail;
    circularDoublyLinkedList()
    {
        tail = nullptr;
    }

    ~circularDoublyLinkedList()
    {
        if (!tail)
            return;
        Node *current = tail->next; // Start from head
        while (current != tail)
        {
            Node *temp = current;
            current = current->next;
            delete temp;
        }
        delete tail;
        tail = nullptr;
    }

    void insertAtHead(int val)
    {
        Node *newNode = new Node(val);
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
        Node *newNode = new Node(val);
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
        Node *r_ptr = tail->next; // Start from head
        while (count < index - 1 && r_ptr != tail)
        {
            count++;
            r_ptr = r_ptr->next;
        }
        if (count == index - 1 && r_ptr != tail)
        {
            Node *newNode = new Node(val);
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
        Node *temp = tail->next;
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
        Node *temp = tail->next;
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
        Node *temp = tail->next;
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
        Node *temp = tail;
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
        Node *current = tail->next; // Start from head
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

class MyCircularDeque3
{
    circularDoublyLinkedList c;
    int capacity;
    int elements;

public:
    MyCircularDeque3(int k)
    {
        capacity = k;
        elements = 0;
    }

    bool insertFront(int value)
    {
        if (isFull())
            return false;
        elements++;
        c.insertAtHead(value);
        return true;
    }

    bool insertLast(int value)
    {
        if (isFull())
            return false;
        elements++;
        c.insertAtTail(value);
        return true;
    }

    bool deleteFront()
    {
        if (isEmpty())
            return false;
        elements--;
        return c.deleteHead();
    }

    bool deleteLast()
    {
        if (isEmpty())
            return false;
        elements--;
        return c.deleteTail();
    }

    int getFront()
    {
        if (isEmpty()) return -1;
        else return c.tail->next->val;
    }

    int getRear()
    {
        if (isEmpty()) return -1;
        else return c.tail->val;
    }

    bool isEmpty()
    {
        return elements == 0;
    }

    bool isFull()
    {
        return elements == capacity;
    }
};


int main()
{
    MyCircularDeque3 deque(3);
    cout << deque.insertLast(1) << endl;  // return true
    cout << deque.insertLast(2) << endl;  // return true
    cout << deque.insertFront(3) << endl; // return true
    cout << deque.insertFront(4) << endl; // return false, the queue is full
    cout << deque.getRear() << endl;      // return 2
    cout << deque.isFull() << endl;       // return true
    cout << deque.deleteLast() << endl;   // return true
    cout << deque.insertFront(4) << endl; // return true
    cout << deque.getFront() << endl;     // return 4
    return 0;
}