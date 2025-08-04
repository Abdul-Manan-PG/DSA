// 557. Reverse Words in the string III

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    void reverseWord(string &s, int i, int j){
        while (i < j){
            swap(s[i], s[j]);
            i++;
            j--;
        }
    }
    
    string reverseWords(string s) {
        int i = 0;
        for (int j = 0; j <= s.length(); j++){
            if (j == s.length() || s[j] == ' '){
                reverseWord(s, i, j - 1);
                i = j + 1;
            }
        }
        return s;
    }
};