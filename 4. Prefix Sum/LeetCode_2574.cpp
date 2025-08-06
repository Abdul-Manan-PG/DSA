// 2574. Left and right Sum Difference

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftDiff(n, 0);
        vector<int> rightDiff(n, 0);
        for (int i = 0; i < n - 1; i++){
            leftDiff[i+1] = leftDiff[i] + nums[i];
        }
        for (int i = n - 1; i > 0; i--){
            rightDiff[i - 1] = rightDiff[i] + nums[i];
        }
        for (int i = 0; i < n; i++){
            if (leftDiff[i] > rightDiff[i])
                nums[i] = leftDiff[i] - rightDiff[i];
            else
                nums[i] = rightDiff[i] - leftDiff[i];
        }
        return nums;
    }
};