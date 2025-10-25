// 268. Missing Number
// https://leetcode.com/problems/missing-number/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int i = 0;
        while (i < nums.size())
        {
            if (nums[i] < nums.size() && nums[i] != i)
            {
                swap(nums[i], nums[nums[i]]);
            }
            else
                i++;
        }
        for (i = 0; i < nums.size(); i++)
        {
            if (i != nums[i])
                return i;
        }
        return nums.size();
    }
};