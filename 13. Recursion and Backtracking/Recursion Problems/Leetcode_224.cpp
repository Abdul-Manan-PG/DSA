// 224. Basic calculator

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        int i = 0;
        return solve(s, i);
    }

    // Solve expression starting at index i
    int solve(const string& s, int &i) {
        long long result = 0;
        long long current = 0;
        int sign = 1;

        while (i < s.size()) {
            char c = s[i];

            if (isdigit(c)) {
                current = current * 10 + (c - '0');
            }
            else if (c == '+') {
                result += sign * current;
                current = 0;
                sign = 1;
            }
            else if (c == '-') {
                result += sign * current;
                current = 0;
                sign = -1;
            }
            else if (c == '(') {
                i++;  
                // recursively evaluate sub-expression
                current = solve(s, i);
            }
            else if (c == ')') {
                // complete this expression level
                result += sign * current;
                return result;
            }

            i++;
        }

        return result + sign * current;
    }
};
