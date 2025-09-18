// 451. Sort characters by frequency

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        // Step 1: Count frequency of each character
        unordered_map<char, int> freq;
        int maxFreq = 0;
        for (char c : s) {
            maxFreq = max(maxFreq, ++freq[c]);
        }

        // Step 2: Create buckets where index = frequency
        vector<vector<char>> buckets(maxFreq + 1);
        for (auto& [ch, count] : freq) {
            buckets[count].push_back(ch);
        }

        // Step 3: Build the result from high frequency to low
        string result;
        for (int i = maxFreq; i > 0; --i) {
            for (char ch : buckets[i]) {
                result.append(i, ch); // append 'ch' i times
            }
        }

        return result;
    }
};
