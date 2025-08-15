// 643. Maximum average Subarray I 

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = 0;
        for (int i = 0; i < k; i++){
            sum += nums[i];
        }
        double max = sum;
        for (int i = k; i < nums.size(); i++){
            sum += nums[i] - nums[i-k];
            if (sum > max) max = sum;
        }
        return max / k;
    }
};