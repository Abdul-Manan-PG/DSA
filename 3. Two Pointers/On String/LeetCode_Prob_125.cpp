// 125. Valid Palindrom

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        if (s.length() < 2) return true;
        int i = 0;
        int j = s.length() - 1;
        while (i < j) {
            if (!(isdigit(s[i]) || isalpha(s[i]))) {
                i++;
                continue;
            }
            if (!(isdigit(s[j]) || isalpha(s[j]))) {
                j--;
                continue;
            }
            if (tolower(s[i]) != tolower(s[j])) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};