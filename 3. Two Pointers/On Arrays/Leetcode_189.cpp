// 189. Rotate array

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution1 { // space O(n)
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> rotated(n);
        for (int i = 0; i < n; i++){
            rotated[((i+k)%n)] = nums[i];
        }
        nums=rotated;
    }
};

class Solution2 { // Space O(1)
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0 || k == 0) return;
        k %= n;
        
        // Helper function to reverse subarray from left to right inclusive
        auto reverse = [&](int left, int right) {
            while (left < right) {
                swap(nums[left], nums[right]);
                left++;
                right--;
            }
        };
        
        // Step 1: Reverse first n-k elements
        reverse(0, n - k - 1);
        
        // Step 2: Reverse last k elements
        reverse(n - k, n - 1);
        
        // Step 3: Reverse the entire array
        reverse(0, n - 1);
    }
};
