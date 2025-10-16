// 1. Two Sum
// Problem:
// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.
//
// Link: `https://leetcode.com/problems/two-sum/`
//
// Constraints (LeetCode):
// - 2 <= nums.length <= 10^4
// - -10^9 <= nums[i] <= 10^9
// - -10^9 <= target <= 10^9
// - Exactly one valid answer exists.
//
// Expected Complexity (hash map):
// - Time: O(n)
// - Space: O(n)

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> num_map;
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (num_map.find(complement) != num_map.end()) {
                return {num_map[complement], i};
            }
            num_map[nums[i]] = i;
        }
        return {}; // return empty vector if no solution found
    }
};

// Solution Complexity (hash map):
// - Time: O(n)
// - Space: O(n)