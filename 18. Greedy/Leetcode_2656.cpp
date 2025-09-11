// 2656. Maximum sum with Exactly K elements

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution1 {
public:
    int maximizeSum(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size() - 1;
        int sum = 0;
        while (k--){
            sum += nums[n];
            nums[n]++;
        }
        return sum;
    }
};

class Solution2 {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int x = *max_element(nums.begin(), nums.end());
        return k * (2 * x + k - 1) / 2;
    }
};
