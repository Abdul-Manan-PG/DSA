// 151. Reverse the words in the string

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        int slow = 0; // position to write
        int fast = 0; // position to read

        // Step 1: Skip leading spaces
        while (fast < n && s[fast] == ' ')
            fast++;

        while (fast < n) {
            // Step 2: Copy non-space characters
            if (s[fast] != ' ') {
                s[slow++] = s[fast++];
            } else {
                // Step 3: Write one space if next word exists
                while (fast < n && s[fast] == ' ')
                    fast++;
                if (fast < n)
                    s[slow++] = ' ';
            }
        }

        // Step 4: Resize to remove trailing characters
        s.resize(slow);
        n = s.length();
        if (n == 0 || n == 1)
            return s;

        // Helper function to reverse subarray from left to right inclusive
        auto reverse = [&](int left, int right) {
            while (left < right) {
                swap(s[left], s[right]);
                left++;
                right--;
            }
        };

        int left = 0;
        for (int i = 0; i < n; i++) {
            if (i > 0 && (s[i] == ' ' || i == n - 1)) {
                if (i == n - 1) {
                    reverse(left, i);
                } else
                    reverse(left, i - 1);
                left = i + 1;
                i++;
            }
        }
        reverse(0, n - 1);
        return s;
    }
};