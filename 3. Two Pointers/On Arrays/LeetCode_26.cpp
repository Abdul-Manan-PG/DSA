// 26. Remove Duplicates from Sorted Array 
// Problem:
// Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place
// such that each unique element appears only once. The relative order of the elements should be kept the same.
//
// Link: `https://leetcode.com/problems/remove-duplicates-from-sorted-array/`
//
// Constraints (LeetCode):
// - 1 <= nums.length <= 3 * 10^4
// - -10^4 <= nums[i] <= 10^4
// - nums is sorted in non-decreasing order.
//
// Expected Complexity (two pointers):
// - Time: O(n)
// - Space: O(1)

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        int uniqueIndex = 0;
        for (int j = 1; j < nums.size(); j++) {
            if (nums[j] != nums[uniqueIndex]) {
                uniqueIndex++;
                nums[uniqueIndex] = nums[j];
            }
        }
        return uniqueIndex + 1;
    }
};

// Solution Complexity (two pointers):
// - Time: O(n)
// - Space: O(1)