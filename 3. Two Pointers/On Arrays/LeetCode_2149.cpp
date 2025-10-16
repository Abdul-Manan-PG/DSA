// 2149. Rearrange Array Elements by Sign
// Problem:
// You are given a 0-indexed integer array nums of even length consisting of an equal number of positive and negative integers.
// Rearrange the array so that the elements with positive and negative integers appear alternately and in the same order as given.
//
// Link: `https://leetcode.com/problems/rearrange-array-elements-by-sign/`
//
// Constraints (LeetCode):
// - 2 <= nums.length <= 2 * 10^5
// - nums.length is even
// - 1 <= |nums[i]| <= 10^5
// - nums contains equal number of positive and negative integers
//
// Expected Complexity:
// - Time: O(n)
// - Space: O(n) (or O(1) if reordering in place is allowed by index tricks)

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> positives, negatives;
        // Separate positives and negatives while preserving order
        for (int num : nums) {
            if (num > 0) {
                positives.push_back(num);
            } else {
                negatives.push_back(num);
            }
        }
        vector<int> res;
        // Merge them alternately
        for (int i = 0; i < positives.size(); ++i) {
            res.push_back(positives[i]);
            res.push_back(negatives[i]);
        }
        return res;
    }
};

// Solution Complexity:
// - Time: O(n)
// - Space: O(n)