// 942. DI string Match

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> diStringMatch(string s) {
        vector <int> perm;
        int i = 0;
        int j = s.length();
        for (int k = 0 ; k < s.length(); k++){
            if (s[k] == 'I'){
                perm.push_back(i++);
            }
            else
                perm.push_back(j--);
        }
        perm.push_back(j);
        return perm;
    }
};