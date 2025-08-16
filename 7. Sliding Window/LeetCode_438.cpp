// 438. Find all ANAGRAMS in a string

#include <iostream>
#include <vector>
#include <string>
#include <array>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) 
    {
        if (s.size() < p.size())
            return { };

        array<int, 26> freq_p = { 0 }, freq_s = { 0 };
        vector<int> res;
        for (int i = 0; i < p.size(); i++)
        {
            freq_p[p[i] - 'a']++;
            freq_s[s[i] - 'a']++;
        }
        if (freq_p == freq_s)
            res.push_back(0);
        for (int i = p.size(); i < s.size(); i++)
        {
            freq_s[s[i] - 'a']++;
            freq_s[s[i - p.size()] - 'a']--;
            if (freq_p == freq_s)
                res.push_back(i - p.size() + 1);
        }
        return res;
    }
};