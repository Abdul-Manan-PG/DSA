// 2000. Reverse the word of Prefix

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string reversePrefix(string word, char ch) {
        int j = 0;
        for (char c : word){
            if (c == ch){
                break;
            }
            j++;
        }
        if (j == word.length() || j == 0){
            return word;
        }
        for (int i = 0; i <= (j / 2); i++){
            swap(word[i], word[j - i]);
        }
        return word;
    }
};