// 2460. Apply Operations to an Array
// Problem:
// You are given a 0-indexed array nums of size n consisting of non-negative integers.
// Apply the following operation until you reach the end of the array:
// If nums[i] == nums[i + 1], then nums[i] becomes nums[i] * 2 and nums[i + 1] becomes 0.
// After all operations, move all zeros to the end of the array.
//
// Link: `https://leetcode.com/problems/apply-operations-to-an-array/`
//
// Constraints (LeetCode):
// - 2 <= n <= 2000
// - 0 <= nums[i] <= 1000
//
// Expected Complexity:
// - Time: O(n)
// - Space: O(1)

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return nums;
        
        // First pass: apply operations
        for (int i = 0; i < n - 1; ++i) {
            if (nums[i] == nums[i + 1]) {
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
        }
        
        // Second pass: move zeros to the end
        int nonZeroIndex = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] != 0) {
                swap(nums[i], nums[nonZeroIndex]);
                ++nonZeroIndex;
            }
        }
        
        return nums;
    }
};

// Solution Complexity:
// - Time: O(n)
// - Space: O(1)