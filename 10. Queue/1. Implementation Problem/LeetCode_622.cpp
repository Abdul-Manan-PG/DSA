// 622. design Circular queue

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class MyCircularQueue {
    vector<int> data;
    int capacity;
    int elements;
    int front;
    int back;

public:
    MyCircularQueue(int k) {
        capacity = k;
        data.resize(k);
        elements = 0;
        front = 0;
        back = 0;
    }
    
    bool enQueue(int value) {
        if (isFull()) {
            return false; // Queue is full
        }
        data[back] = value; // Add the new element
        back = (back + 1) % capacity; // Move back to the next position
        elements++; // Increment the count of elements
        return true; // Successfully added
    }
    
    bool deQueue() {
        if (isEmpty()) {
            return false; // Queue is empty
        }
        front = (front + 1) % capacity; // Move front to the next position
        elements--; // Decrement the count of elements
        return true; // Successfully removed
    }
    
    int Front() {
        if (isEmpty()) {
            return -1; // Queue is empty
        }
        return data[front]; // Return the front element
    }
    
    int Rear() {
        if (isEmpty()) {
            return -1; // Queue is empty
        }
        return data[(back - 1 + capacity) % capacity]; // Return the rear element
    }
    
    bool isEmpty() {
        return (elements == 0); // Check if the queue is empty
    }
    
    bool isFull() {
        return (elements == capacity); // Check if the queue is full
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
