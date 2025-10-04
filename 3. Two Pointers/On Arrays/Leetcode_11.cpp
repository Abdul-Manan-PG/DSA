// 11. Container with most water

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left = 0; // Pointer starting from the beginning
        int right = n - 1; // Pointer starting from the end
        int max_area = 0; // Variable to store the maximum area found

        while (left < right) {
            // Calculate the width of the container
            int width = right - left;
            // Calculate the height of the container, which is the minimum of the two heights
            int h = min(height[left], height[right]);
            // Calculate the area
            int area = width * h;
            // Update the maximum area if the current area is larger
            max_area = max(max_area, area);

            // Move the pointer that points to the shorter line
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return max_area;
    }
};