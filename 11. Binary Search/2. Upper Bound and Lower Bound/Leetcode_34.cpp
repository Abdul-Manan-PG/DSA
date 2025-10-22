// 34. Find first and start position of Element in sorted array

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) return {-1, -1};
        
        // Find the first occurrence
        int low = 0, high = n - 1;
        int start = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] >= target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        if (low < n && nums[low] == target) {
            start = low;
        }
        
        // Find the last occurrence
        low = 0, high = n - 1;
        int end = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] <= target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        if (high >= 0 && nums[high] == target) {
            end = high;
        }
        
        return {start, end};
    }
};