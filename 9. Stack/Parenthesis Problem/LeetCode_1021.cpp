// 1021. Remove outermost Parenthesis

#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution1 {
public:
    string removeOuterParentheses(string s) {
        stack<char> st;
        string res = "";
        for (char c : s) {
            if (c == '('){
                st.push(c);
            }
            if (st.size() > 1){
                res += c;
            }
            if (c == ')'){
                st.pop();
            }
        }
        return res;
    }
};

class Solution2 {
public:
    string removeOuterParentheses(string s) {
        stack<char> st;
        string result;
        int nesting_level = 0;
        
        for (char c : s) {
            if (c == '(') {
                nesting_level++;
                if (nesting_level > 1) {
                    result += c;
                }
            } else { // c == ')'
                if (nesting_level > 1) {
                    result += c;
                }
                nesting_level--;
            }
        }
        
        return result;
    }
};
