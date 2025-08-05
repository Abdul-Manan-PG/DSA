// 680. Valid Palindrome II

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool validPalindrome(string s) {
        int count1 = 0;
        int j = s.length() - 1;
        int i = 0;
        while (i < j) {
            if (s[i] != s[j]) {
                count1++;
                j--;
            } else {
                i++;
                j--;
            }
        }
        i = 0;
        j = s.length() - 1;
        int count2 = 0;
        while (i < j){
            if (s[i] != s[j]){
                count2++;
                i++;
            }
            else{
                i++;
                j--;
            }
        }
        if (count1 <= 1 || count2 <= 1)
            return true;
        else
            return false;
    }
};