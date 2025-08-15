// 1876. Substrings of size three with distinct characters

#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Solution {
public:
    int countGoodSubstrings(string s) {
        if(s.size() < 3)
        return 0;

        int ans = 0;
        for(int i = 2; i<s.length(); i++){
            if(s[i-2] != s[i-1] && s[i-1] != s[i] && s[i-2] != s[i])
            ans++;
        }
        return ans;
    }
};