// 28. Find the index of first occurance in a string

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) {
            return 0; // Standard behavior: empty needle is always at index 0
        }
        for (size_t i = 0; i + needle.size() <= haystack.size(); ++i) {
            if (haystack[i] == needle[0]) { // Optional optimization: skip if
                                            // first char doesn't match
                bool match = true;
                for (size_t j = 0; j < needle.size(); ++j) {
                    if (haystack[i + j] != needle[j]) {
                        match = false;
                        break;
                    }
                }
                if (match) {
                    return static_cast<int>(
                        i); // Cast back to int for return type
                }
            }
        }
        return -1;
    }
};