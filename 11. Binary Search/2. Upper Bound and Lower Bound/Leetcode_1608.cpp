// 1608. Special Array With X Elements Greater Than or Equal X

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),
             nums.end()); // Sort the array to apply binary search logic

        int low = 0;
        int high = n - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            // Check if nums[mid] is greater than or equal to n - mid
            if (nums[mid] >= n - mid) {
                // Check if this is the first element or the previous element is
                // less than n - mid
                if (mid == 0 || nums[mid - 1] < n - mid) {
                    return n - mid; // This is the special index
                } else {
                    high = mid - 1; // Continue searching in the left half
                }
            } else {
                low = mid + 1; // Continue searching in the right half
            }
        }

        return -1; // If no special index is found
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3, 5};
    cout << sol.specialArray(nums) << endl; // Output: 2
    return 0;
}