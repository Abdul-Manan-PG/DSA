// 232. Queue from stack

#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;



class MyQueue {
private:
    stack<int> st_in;  // Stack for enqueue operations
    stack<int> st_out; // Stack for dequeue operations

public:
    MyQueue() {}

    void push(int x) {
        st_in.push(x); // Push onto the input stack
    }

    int pop() {
        if (st_out.empty()) {
            // Transfer elements from st_in to st_out to reverse order
            while (!st_in.empty()) {
                st_out.push(st_in.top());
                st_in.pop();
            }
        }
        int element = st_out.top();
        st_out.pop();
        return element; // Return the front element
    }

    int peek() {
        if (st_out.empty()) {
            // Transfer elements from st_in to st_out to reverse order
            while (!st_in.empty()) {
                st_out.push(st_in.top());
                st_in.pop();
            }
        }
        return st_out.top(); // Return the front element without removing it
    }

    bool empty() {
        return st_in.empty() && st_out.empty(); // Check if both stacks are empty
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
