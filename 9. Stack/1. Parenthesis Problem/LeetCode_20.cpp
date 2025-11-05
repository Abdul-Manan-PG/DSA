// 20. Valid Parentheses
// Problem:
// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']'
// determine if the input string is valid. An input string is valid if:
// 1) Open brackets must be closed by the same type of brackets.
// 2) Open brackets must be closed in the correct order.
//
// Link: `https://leetcode.com/problems/valid-parentheses/`
//
// Constraints (LeetCode):
// - 1 <= s.length <= 10^4
// - s consists of parentheses only
//
// Expected Complexity:
// - Stack-based validation: Time O(n), Space O(n)

#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
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

// Solution1 Complexity (Manual checks with stack):
// - Time: O(n)
// - Space: O(n)

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

// Solution2 Complexity (Map + stack):
// - Time: O(n)
// - Space: O(n)