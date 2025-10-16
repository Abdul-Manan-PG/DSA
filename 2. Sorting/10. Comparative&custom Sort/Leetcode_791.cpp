// 791. Custom Sort String
// Problem:
// Given two strings order and s. Order is a permutation of the lowercase letters.
// Reorder the characters of s so that they match the order given in order. Characters
// not in order can be placed anywhere at the end. Return any valid answer.
//
// Link: `https://leetcode.com/problems/custom-sort-string/`
//
// Constraints (LeetCode):
// - 1 <= order.length <= 26
// - 1 <= s.length <= 200
// - order and s consist of lowercase English letters.
//
// Expected Complexity (typical hashmap approach):
// - Time: O(|order| + |s|)
// - Space: O(1) for alphabet-sized counts
//
// Note on this implementation:
// - Uses index collection and erase; worst-case can be higher due to repeated erasures.
//
// Sample Test Cases:
// 1) order = "cba", s = "abcd" -> "cbad"
// 2) order = "bcafg", s = "abcd" -> "bcad"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string customSortString(string order, string s) {
        string str = "";
        for (int i = 0; i < order.length(); i++) {
            vector<int> index;
            for (int j = 0; j < s.length(); j++) {
                if (order[i] == s[j]) {
                    str += order[i];
                    index.push_back(j);
                }
            }
            for (int k = 0; k < index.size(); k++) {
                s.erase(index[k] - k, 1);
            }
        }
        str += s;
        return str;
    }
};

int main() {
    Solution sol;
    
    // Test case 1
    string order1 = "cba";
    string s1 = "abcd";
    string result1 = sol.customSortString(order1, s1);
    cout << "Test case 1: order = \"" << order1 << "\", s = \"" << s1 << "\"" << endl;
    cout << "Result: " << result1 << endl;
    cout << "Expected: cbad" << endl << endl;
    
    // Test case 2
    string order2 = "bcafg";
    string s2 = "abcd";
    string result2 = sol.customSortString(order2, s2);
    cout << "Test case 2: order = \"" << order2 << "\", s = \"" << s2 << "\"" << endl;
    cout << "Result: " << result2 << endl;
    cout << "Expected: bcad" << endl << endl;
    
    // Test case 3
    string order3 = "kqep";
    string s3 = "pekeq";
    string result3 = sol.customSortString(order3, s3);
    cout << "Test case 3: order = \"" << order3 << "\", s = \"" << s3 << "\"" << endl;
    cout << "Result: " << result3 << endl;
    cout << "Expected: kqeep" << endl << endl;
    
    // Test case 4 (empty string)
    string order4 = "";
    string s4 = "abcd";
    string result4 = sol.customSortString(order4, s4);
    cout << "Test case 4: order = \"" << order4 << "\", s = \"" << s4 << "\"" << endl;
    cout << "Result: " << result4 << endl;
    cout << "Expected: abcd" << endl << endl;
    
    // Test case 5 (order has characters not in s)
    string order5 = "xyz";
    string s5 = "abcd";
    string result5 = sol.customSortString(order5, s5);
    cout << "Test case 5: order = \"" << order5 << "\", s = \"" << s5 << "\"" << endl;
    cout << "Result: " << result5 << endl;
    cout << "Expected: abcd" << endl << endl;
    
    return 0;
}

// Solution Complexity (typical approach):
// - Time: O(|order| + |s|)
// - Space: O(1) for fixed alphabet counts