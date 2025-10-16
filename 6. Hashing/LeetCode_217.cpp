// 217. Contains Duplicate
// Problem:
// Given an integer array nums, return true if any value appears at least twice in the array,
// and return false if every element is distinct.
//
// Link: `https://leetcode.com/problems/contains-duplicate/`
//
// Constraints (LeetCode):
// - 1 <= nums.length <= 10^5
// - -10^9 <= nums[i] <= 10^9
//
// Expected Complexity:
// - Hash-based detection: Time O(n), Space O(n)

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution1 {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> n;
        for (int i = 0; i < nums.size(); i++){
            if (n.find(nums[i]) == n.end()){
                n.emplace(nums[i], 1);
            }
            else
                return true;
        }
        return false;
    }
};

// Solution1 Complexity (unordered_map presence check):
// - Time: O(n)
// - Space: O(n)

class Solution2 {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        for (int num : nums) {
            if (seen.find(num) != seen.end()) {
                return true;
            }
            seen.insert(num);
        }
        return false;
    }
};

// Solution2 Complexity (unordered_set presence check):
// - Time: O(n)
// - Space: O(n)