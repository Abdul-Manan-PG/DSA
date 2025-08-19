// 1614. Maximum Nesting Depth of Parenthesis

#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        stack<char> st;
        int Max_size = 0;
        for (char c : s) {
            if (c == '(') {
                st.push(c);
                // Update Max_size after pushing to the stack
                Max_size = max(Max_size, (int)st.size());
            }
            if (c == ')' && !st.empty()) {
                st.pop();
            }
        }
        return Max_size;
    }
};
