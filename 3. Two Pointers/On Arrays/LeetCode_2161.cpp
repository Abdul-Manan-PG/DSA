// 2161. Partition Array According to Given Pivot
// Problem:
// Given an integer array nums and an integer pivot, you have to partition nums into:
// - All elements less than pivot, followed by
// - All elements equal to pivot, followed by
// - All elements greater than pivot.
// Return the partitioned array.
//
// Link: `https://leetcode.com/problems/partition-array-according-to-given-pivot/`
//
// Constraints (LeetCode):
// - 1 <= nums.length <= 10^5
// - -10^6 <= nums[i] <= 10^6
// - -10^6 <= pivot <= 10^6
//
// Expected Complexity:
// - Time: O(n)
// - Space: O(n)

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> small;
        vector<int> large;
        int count = 0;
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] > pivot){
                large.push_back(nums[i]);
            }
            else if (nums[i] < pivot){
                small.push_back(nums[i]);
            }
            else
                count++;
        }
        vector<int> res;
        for (int i : small){
            res.push_back(i);
        }
        for (int i = 0; i < count; i++){
            res.push_back(pivot);
        }
        for (int i : large){
            res.push_back(i);
        }
        return res;
    }
};

// Solution Complexity:
// - Time: O(n)
// - Space: O(n)