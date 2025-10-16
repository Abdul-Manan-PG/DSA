// 1122. Relative Sort Array
// Problem:
// Given two arrays arr1 and arr2, the elements of arr2 are distinct, and all elements
// in arr2 are present in arr1. Sort the elements of arr1 such that the relative order
// of items in arr1 are the same as in arr2. Elements that do not appear in arr2 should
// be placed at the end of arr1 in ascending order.
//
// Link: `https://leetcode.com/problems/relative-sort-array/`
//
// Constraints (LeetCode):
// - 1 <= arr1.length, arr2.length <= 1000
// - 0 <= arr1[i], arr2[i] <= 1000
// - All elements of arr2 are distinct.
// - Each element in arr2 appears in arr1.
//
// Expected Complexity:
// - Counting sort solution (Solution1): Time O(n + K), Space O(K) where K = max(arr1)
// - Map + sort solution (Solution2): Time O(n log n), Space O(n)
//
// Sample Test Case:
// Input:  arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
// Output: [2,2,2,1,4,3,3,9,6,7,19]

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution1 
{
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int maxVal = *max_element(arr1.begin(), arr1.end());
        vector<int> count(maxVal + 1, 0);

        // Count frequency of each number in arr1
        for (int num : arr1) {
            count[num]++;
        }

        vector<int> result;

        // Place elements from arr2 first, in order
        for (int num : arr2) {
            while (count[num] > 0) {
                result.push_back(num);
                count[num]--;
            }
        }

        // Place remaining elements in ascending order
        for (int i = 0; i <= maxVal; i++) {
            while (count[i] > 0) {
                result.push_back(i);
                count[i]--;
            }
        }

        return result;
    }
};

// Solution1 Complexity (Counting Sort):
// - Time: O(n + K), where K = max(arr1)
// - Space: O(K)


class Solution2 {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> freq;
        for (int num : arr1) {
            freq[num]++;  // count frequency of each number
        }

        vector<int> result;

        // Add elements from arr2 first, in order
        for (int num : arr2) {
            while (freq[num] > 0) {
                result.push_back(num);
                freq[num]--;
            }
        }

        // Collect remaining elements
        vector<int> remaining;
        for (auto &p : freq) {
            while (p.second > 0) {
                remaining.push_back(p.first);
                p.second--;
            }
        }

        // Sort remaining in ascending order
        sort(remaining.begin(), remaining.end());

        // Append remaining to result
        result.insert(result.end(), remaining.begin(), remaining.end());

        return result;
    }
};

// Solution2 Complexity (HashMap + Sort Remaining):
// - Time: O(n log n)
// - Space: O(n)