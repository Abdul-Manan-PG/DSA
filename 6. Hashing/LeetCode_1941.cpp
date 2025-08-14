// 1941. Check all characters have equal numbers of occurence

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool areOccurrencesEqual(string s) {
        unordered_map<char, int> m;
        for (char c : s) {
            m[c]++;
        }

        if (m.empty()) {
            return true;
        }

        int first_freq = m.begin()->second;
        for (const auto& pair : m) {
            if (pair.second != first_freq) {
                return false;
            }
        }

        return true;
    }
};