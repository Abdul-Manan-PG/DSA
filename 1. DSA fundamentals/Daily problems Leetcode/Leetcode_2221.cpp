// 2221. Find the triangular sum of Array

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size() - 1;
        while (n > 0){
            for (int i = 0; i < n; i++){
                nums[i] += nums[i+1];
                nums[i] %= 10;
            }
            n--;
        }
        return nums[0];
    }
};