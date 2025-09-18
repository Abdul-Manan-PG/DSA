// 1122. Relative Sort Array

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