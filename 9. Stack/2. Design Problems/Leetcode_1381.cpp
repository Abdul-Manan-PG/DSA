// 1381. Design a Stack With Increment Operation

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class CustomStack {
    vector<int> stk;
    vector<int> lazy;
    int maxsz;
public:
    CustomStack(int maxSize) {
        maxsz = maxSize;
    }
    
    void push(int x) {
        if (stk.size() < maxsz) {
            stk.push_back(x);
            lazy.push_back(0);
        }
    }
    
    int pop() {
        if (stk.empty()) return -1;
        int res = stk.back() + lazy.back();
        stk.pop_back();
        lazy.pop_back();
        return res;
    }
    
    void increment(int k, int val) {
        int n = stk.size();
        for (int i = 0; i < min(k, n); i++) {
            lazy[i] += val;
        }
    }
};


// Solution Complexity:
// - Time: O(1) for push and pop, O(k) for increment