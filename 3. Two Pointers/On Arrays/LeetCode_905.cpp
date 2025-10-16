// 905. Sort Array By Parity
// Problem:
// Given an integer array nums, move all the even integers at the beginning of the array followed by all the odd integers.
// Return any array that satisfies this condition.
//
// Link: `https://leetcode.com/problems/sort-array-by-parity/`
//
// Constraints (LeetCode):
// - 1 <= nums.length <= 5000
// - 0 <= nums[i] <= 5000
//
// Expected Complexity:
// - Time: O(n)
// - Space: O(1)
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution // time complexity O(n)
{
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int i = 0, j = 0;
        while (j < nums.size()){
            if (nums[j] % 2 == 0){
                swap(nums[j], nums[i]);
                i++;
                j++;
            }
            else
            j++;
        }
        return nums;
    }
};

// Solution Complexity:
// - Time: O(n)
// - Space: O(1)