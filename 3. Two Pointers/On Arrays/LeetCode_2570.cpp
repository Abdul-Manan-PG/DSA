// 2570. Merge Two 2D Arrays by Summing Values
// Problem:
// You are given two 2D integer arrays nums1 and nums2, where each array has the form [id, val] and is sorted by id.
// Merge the arrays by adding values with the same id, and return the result sorted by id.
//
// Link: `https://leetcode.com/problems/merge-two-2d-arrays-by-summing-values/`
//
// Constraints (LeetCode):
// - 1 <= nums1.length, nums2.length <= 200
// - nums1[i].length == nums2[j].length == 2
// - ids are unique within each array and arrays are sorted by id
//
// Expected Complexity (two-pointer merge):
// - Time: O(n + m)
// - Space: O(n + m) for result

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<vector<int>> results;
        int i = 0, j = 0;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i][0] == nums2[j][0]) {
                results.push_back({nums1[i][0], nums1[i][1] + nums2[j][1]});
                i++;
                j++;
            }
            else if (nums1[i][0] < nums2[j][0]) {
                results.push_back({nums1[i][0], nums1[i][1]});
                i++;
            }
            else {
                results.push_back({nums2[j][0], nums2[j][1]});
                j++;
            }
        }
        while (i < nums1.size()) {
            results.push_back({nums1[i][0], nums1[i][1]});
            i++;
        }
        while (j < nums2.size()) {
            results.push_back({nums2[j][0], nums2[j][1]});
            j++;
        }
        return results;
    }
};

// Helper function to print a 2D vector
void printResult(const vector<vector<int>>& res) {
    cout << "[";
    for (size_t i = 0; i < res.size(); ++i) {
        cout << "[" << res[i][0] << "," << res[i][1] << "]";
        if (i != res.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
}

int main() {
    Solution sol;

    // Test Case 1
    vector<vector<int>> nums1 = {{1, 2}, {2, 3}, {4, 5}};
    vector<vector<int>> nums2 = {{1, 4}, {3, 2}, {4, 1}};
    vector<vector<int>> result1 = sol.mergeArrays(nums1, nums2);
    cout << "Test Case 1: ";
    printResult(result1);  // Expected: [[1,6], [2,3], [3,2], [4,6]]

    // Test Case 2
    vector<vector<int>> nums3 = {{1, 1}};
    vector<vector<int>> nums4 = {{1, 3}};
    vector<vector<int>> result2 = sol.mergeArrays(nums3, nums4);
    cout << "Test Case 2: ";
    printResult(result2);  // Expected: [[1,4]]

    // Test Case 3 (One empty input)
    vector<vector<int>> nums5 = {};
    vector<vector<int>> nums6 = {{2, 5}, {6, 7}};
    vector<vector<int>> result3 = sol.mergeArrays(nums5, nums6);
    cout << "Test Case 3: ";
    printResult(result3);  // Expected: [[2,5], [6,7]]

    return 0;
}

// Solution Complexity:
// - Time: O(n + m)
// - Space: O(n + m)