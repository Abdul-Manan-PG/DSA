// 27. Remove Element
// Problem:
// Given an integer array nums and an integer val, remove all occurrences of val in nums in-place.
// The relative order of the elements may be changed.
//
// Link: `https://leetcode.com/problems/remove-element/`
//
// Constraints (LeetCode):
// - 0 <= nums.length <= 100
// - 0 <= nums[i] <= 50
// - 0 <= val <= 100
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
    int removeElement(vector<int>& nums, int val) {
        if (nums.empty())
            return 0;
        int i = 0, n = nums.size();
        while (i < n) {
            if (nums[i] == val) {
                swap(nums[i], nums[n - 1]);
                n--;
            } else
                i++;
        }
        return n;
    }
};

// Solution Complexity:
// - Time: O(n)
// - Space: O(1)