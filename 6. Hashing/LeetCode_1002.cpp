// 1002. Find common Characters 

#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        if (words.empty()) return {};
        
        vector<int> minFreq(26, INT_MAX);
        
        for (const string& word : words) {
            vector<int> currentFreq(26, 0);
            for (char c : word) {
                currentFreq[c - 'a']++;
            }
            for (int i = 0; i < 26; ++i) {
                minFreq[i] = min(minFreq[i], currentFreq[i]);
            }
        }
        
        vector<string> result;
        for (int i = 0; i < 26; ++i) {
            while (minFreq[i]-- > 0) {
                result.push_back(string(1, 'a' + i));
            }
        }
        
        return result;
    }
};