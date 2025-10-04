// 2460. Apply operation to array

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return nums;
        
        // First pass: apply operations
        for (int i = 0; i < n - 1; ++i) {
            if (nums[i] == nums[i + 1]) {
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
        }
        
        // Second pass: move zeros to the end
        int nonZeroIndex = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] != 0) {
                swap(nums[i], nums[nonZeroIndex]);
                ++nonZeroIndex;
            }
        }
        
        return nums;
    }
};