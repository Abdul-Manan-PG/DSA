// 921. Minimum Add to Make Parentheses Valid

#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    int minAddToMakeValid(string s) {
        int extra = 0;
        stack<char> st;
        for (char c : s) {
            if (c == '(') {
                st.push(c);
            }
            if (c == ')') {
                if (st.size() > 0)
                    st.pop();
                else 
                    extra++;
            }
        }
        return st.size() + extra;
    }
};

int main() {
    Solution sol;
    string s = "())";
    cout << sol.minAddToMakeValid(s) << endl; // Output: 1
    return 0;
}