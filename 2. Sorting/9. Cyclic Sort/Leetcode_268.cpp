// 268. Missing Number
// Problem:
// Given an array nums containing n distinct numbers in the range [0, n], return
// the only number in the range that is missing from the array.
//
// Link: `https://leetcode.com/problems/missing-number/`
//
// Constraints (LeetCode):
// - n == nums.length
// - 1 <= n <= 10^4
// - 0 <= nums[i] <= n
// - All the numbers of nums are unique.
//
// Expected Complexity (cyclic sort/index placement):
// - Time: O(n)
// - Space: O(1)
//
// Sample Test Cases:
// 1) nums = [3,0,1] -> 2
// 2) nums = [0,1]   -> 2
// 3) nums = [9,6,4,2,3,5,7,0,1] -> 8

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int i = 0;
        while (i < nums.size()){
            if (nums[i] < nums.size() && nums[i] != i){
                swap(nums[i], nums[nums[i]]);
            }
            else 
                i++;
        }
        for (i = 0; i < nums.size(); i++){
            if (i != nums[i])
                return i;
        }
        return nums.size();
    }
};

int main(){
    vector<int> arr = {1, 2, 5, 4, 3, 0};
    Solution s;
    cout << "Missing number is " << s.missingNumber(arr) << endl;
    return 0;
}

// Solution Complexity:
// - Time: O(n)
// - Space: O(1)