// 1768. Merge strings alternatively

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ret = "";
        int i = 0, j = 0;
        while (i < word1.length() && j < word2.length()){
            ret += word1[i++];
            ret += word2[j++];
        }
        while (i < word1.length()){
            ret += word1[i++];
        }
        while (j < word2.length()){
            ret+= word2[j++];
        }
        return ret;
    }
};