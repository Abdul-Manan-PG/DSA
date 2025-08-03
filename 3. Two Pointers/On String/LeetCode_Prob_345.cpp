// 345. Reverse the vowels in string

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool vowel(char x) {
        if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u' ||
            x == 'A' || x == 'E' || x == 'I' || x == 'O' || x == 'U')
            return true;
        else
            return false;
    }
    string reverseVowels(string s) {
        int i = 0;
        int j = s.length() - 1;
        while (i < j) {
            if (vowel(s[i]) && vowel(s[j])) {
                swap(s[i], s[j]);
                i++;
                j--;
            } else if (vowel(s[i])) {
                j--;
            } else if (vowel(s[j])) {
                i++;
            } else {
                i++;
                j--;
            }
        }
        return s;
    }
};