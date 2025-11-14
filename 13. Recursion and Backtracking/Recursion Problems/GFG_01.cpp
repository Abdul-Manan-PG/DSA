// GFG. Delete the middle of stack

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    void Helper(stack<int>& s, int current, int mid){
        // When we reach the middle index, remove element
        if (current == mid) {
            s.pop();
            return;
        }

        int x = s.top();
        s.pop();

        Helper(s, current + 1, mid);

        s.push(x);
    }

    void deleteMid(stack<int>& s) {
        if (s.empty()) return;

        int mid = s.size() / 2;   // fixed midpoint (constant)
        Helper(s, 0, mid);
    }
};
