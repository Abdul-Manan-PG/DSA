// 35. Search Insert Position

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& arr, int target) {
        int low = 0;
        int high = arr.size() - 1;

        while (low <= high) {
            // Prevents potential integer overflow compared to (low + high) / 2
            int mid = low + (high - low) / 2;

            // Check if target is present at mid
            if (arr[mid] == target) {
                return mid; // Target found
            }
            // If target is greater, ignore left half
            else if (arr[mid] < target) {
                low = mid + 1;
            }
            // If target is smaller, ignore right half
            else {
                high = mid - 1;
            }
        }
        // Target was not present in the array it would be place at left index
        return low;
    }
};