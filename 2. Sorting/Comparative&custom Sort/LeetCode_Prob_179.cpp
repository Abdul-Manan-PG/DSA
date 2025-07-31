#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        // Convert numbers to strings
        vector<string> numStrs;
        for (int num : nums) {
            numStrs.push_back(to_string(num));
        }
        
        // Custom comparator to sort strings
        auto cmp = [](const string& a, const string& b) {
            return a + b > b + a;
        };
        
        // Sort the strings using our custom comparator
        sort(numStrs.begin(), numStrs.end(), cmp);
        
        // Handle case where largest number is 0
        if (numStrs[0] == "0") {
            return "0";
        }
        
        // Concatenate all strings
        string result;
        for (const string& s : numStrs) {
            result += s;
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    
    // Test cases
    vector<vector<int>> testCases = {
        {10, 2},             // Expected: "210"
        {3, 30, 34, 5, 9},    // Expected: "9534330"
        {1},                  // Expected: "1"
        {10},                 // Expected: "10"
        {0, 0},               // Expected: "0"
        {999999998, 999999997, 999999999} // Expected: "999999999999999998999999997"
    };
    
    for (int i = 0; i < testCases.size(); i++) {
        string result = sol.largestNumber(testCases[i]);
        cout << "Test case " << i+1 << ": ";
        for (int num : testCases[i]) {
            cout << num << " ";
        }
        cout << "\nResult: " << result << endl << endl;
    }
    
    return 0;
}