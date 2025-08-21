// 225. Making stack stl with queue (1 or 2)

#include <iostream>
#include <queue>
#include <string>
using namespace std;

class MyStack1 {
private:
    queue<int> myQ;

public:
    MyStack() {}

    void push(int x) {
        myQ.push(x);
    }

    int pop() {
        // Rotate the queue to make the last pushed element at the front
        for (int i = 0; i < myQ.size() - 1; i++) {
            myQ.push(myQ.front());
            myQ.pop();
        }
        int topElement = myQ.front();
        myQ.pop();
        return topElement;
    }

    int top() {
        return myQ.back();
    }

    bool empty() {
        return myQ.empty();
    }
};


class MyStack2 {
private:
    queue<int> q1;
    queue<int> q2;
    int activeQueue; // 1: q1 is active (most elements), 2: q2 is active

public:
    MyStack() : activeQueue(1) {}

    void push(int x) {
        if (activeQueue == 1) {
            q1.push(x);
        } else {
            q2.push(x);
        }
    }

    int pop() {
        int topElement;
        if (activeQueue == 1) {
            // Move all but last element to q2
            while (q1.size() > 1) {
                q2.push(q1.front());
                q1.pop();
            }
            topElement = q1.front();
            q1.pop();
            activeQueue = 2;  // Switch active queue
        } else {
            // Move all but last element to q1
            while (q2.size() > 1) {
                q1.push(q2.front());
                q2.pop();
            }
            topElement = q2.front();
            q2.pop();
            activeQueue = 1;  // Switch active queue
        }
        return topElement;
    }

    int top() {
        int topElement;
        if (activeQueue == 1) {
            // Move all elements to q2 temporarily
            while (!q1.empty()) {
                topElement = q1.front();
                q2.push(topElement);
                q1.pop();
            }
            activeQueue = 2;  // Now q2 is active
        } else {
            // Move all elements to q1 temporarily
            while (!q2.empty()) {
                topElement = q2.front();
                q1.push(topElement);
                q2.pop();
            }
            activeQueue = 1;  // Now q1 is active
        }
        return topElement;
    }

    bool empty() {
        return (activeQueue == 1 ? q1.empty() : q2.empty());
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
