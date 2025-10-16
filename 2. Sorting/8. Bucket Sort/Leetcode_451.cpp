// 451. Sort Characters by Frequency
// Problem:
// Given a string s, sort it in decreasing order based on the frequency of the characters.
// The frequency of a character is the number of times it appears in the string.
// Return the sorted string. If there are multiple answers, return any of them.
//
// Link: `https://leetcode.com/problems/sort-characters-by-frequency/`
//
// Constraints (LeetCode):
// - 1 <= s.length <= 5 * 10^5
// - s consists of uppercase/lowercase English letters and digits.
//
// Expected Complexity (bucket approach):
// - Time: O(n + U + B) ~ O(n), where U is number of unique chars, B is max frequency
// - Space: O(n + U)
//
// Sample Test Cases:
// 1) Input: s = "tree" -> Output: "eert" or "eetr"
// 2) Input: s = "cccaaa" -> Output: "cccaaa" or "aaaccc"
// 3) Input: s = "Aabb" -> Output: "bbAa" or "bbaA"

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

// Solution Complexity:
// - Time: O(n)
// - Space: O(n)
