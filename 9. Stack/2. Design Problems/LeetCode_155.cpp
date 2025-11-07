// 155. Min stack 

#include <iostream>
#include <vector>
#include <string>
using namespace std;


// Time efficient

class MinStack {
private:
    vector<int> stack;
    vector<int> minStack;
public:
    MinStack() {}

    void push(int val) {
        stack.push_back(val);
        // Push to minStack if it's empty or the new value is smaller or equal to the current minimum
        if (minStack.empty() || val <= minStack.back()) {
            minStack.push_back(val);
        }
    }

    void pop() {
        if (stack.empty()) return;
        int topValue = stack.back();
        stack.pop_back();
        // If the popped value is the minimum, pop it from minStack as well
        if (topValue == minStack.back()) {
            minStack.pop_back();
        }
    }

    int top() {
        if (!stack.empty()) return stack.back();
        return 0; // or throw an exception
    }

    int getMin() {
        if (!minStack.empty()) return minStack.back();
        return 0; // or throw an exception
    }
};


// Space efficient
class MinStack {
public:
    MinStack() {
    }
    
    void push(int val) {
        stack.push_back(val);
    }
    
    void pop() {
        if(!stack.empty()) stack.pop_back();
    }
    
    int top() {
        if (stack.empty()) return -1;
        return stack[stack.size() - 1];
    }
    
    int getMin() {
        if (stack.empty()) return -1;

        int minn = stack[0];
        for (int ptr = 1; ptr < stack.size(); ptr++) {
            if (stack[ptr] < minn) minn = stack[ptr]; 
        }
        return minn;
    }
private:
    vector<int> stack;
};