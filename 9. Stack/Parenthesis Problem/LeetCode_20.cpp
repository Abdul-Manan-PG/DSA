// 20. Valid parenthesis

#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution1
{
public:
    bool isValid(string s) {
        stack<char> st;
        for (char c : s){
            if (c == '(' || c == '{' || c == '['){
                st.push(c);
                continue;
            }
            if (c == ')'){
                if (st.empty()) return false;
                if (st.top() == '(') st.pop();
                else return false;
            }
            if (c == ']'){
                if (st.empty()) return false;
                if (st.top() == '[') st.pop();
                else return false;
            }
            if (c == '}'){
                if (st.empty()) return false;
                if (st.top() == '{') st.pop();
                else return false;
            }
        }
        if (st.empty()) return true;
        return false;
    }
};

class Solution2 
{
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> pairs = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };
        
        for (char c : s) {
            if (pairs.find(c) == pairs.end()) {
                // It's an opening bracket
                st.push(c);
            } else {
                // It's a closing bracket
                if (st.empty() || st.top() != pairs[c]) {
                    return false;
                }
                st.pop();
            }
        }
        
        return st.empty();
    }
};