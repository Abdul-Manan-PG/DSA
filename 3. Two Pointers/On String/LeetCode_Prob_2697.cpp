// 2697. Lexicographically smallest palindrom

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string makeSmallestPalindrome(string s) {
        int j = s.length() - 1;
        int i = 0;
        while (i < j) {
            if (s[i] != s[j]) {
                if (s[i] < s[j]){
                    s[j] = s[i];
                }
                else
                    s[i] = s[j];
                i++;
                j--;
            } else {
                i++;
                j--;
            }
        }
        return s;
    }
};