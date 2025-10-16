// 922. Sort Array By Parity II
// Problem:
// Given an array of integers nums of even length, return an array such that:
// - Every element at an even index is even, and
// - Every element at an odd index is odd.
//
// Link: `https://leetcode.com/problems/sort-array-by-parity-ii/`
//
// Constraints (LeetCode):
// - 2 <= nums.length <= 2 * 10^4
// - nums.length is even
// - 0 <= nums[i] <= 1000
// - There are as many even numbers as odd numbers in nums
//
// Expected Complexity:
// - Time: O(n)
// - Space: O(1)

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution 
{
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int i = 0, j = 0;
        while (i < nums.size() - 1) {
            if (i % 2 == 0) // if even index
            {
                if (nums[i] % 2 == 0) //  if even value at even index
                {
                    i++;
                    j = i;
                } else // if odd value at even index
                {
                    if (nums[j] % 2 == 0) {
                        swap(nums[i], nums[j]);
                        i++;
                        j = i;
                    } else
                        j++;
                }
            } else // if odd index
            {
                if (nums[i] % 2 != 0) //  if odd value at odd index
                {
                    i++;
                    j = i;
                }
                else // if even value at odd index
                {
                    if (nums[j] % 2 != 0){
                        swap (nums[i], nums[j]);
                        i++;
                        j = i;
                    }
                    else
                    j++;
                }
            }
        }
        return nums;
    }
};

// Solution Complexity:
// - Time: O(n)
// - Space: O(1)