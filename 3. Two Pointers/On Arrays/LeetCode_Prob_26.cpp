// 26. Remove Duplicates from sorted array 

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        int uniqueIndex = 0;
        for (int j = 1; j < nums.size(); j++) {
            if (nums[j] != nums[uniqueIndex]) {
                uniqueIndex++;
                nums[uniqueIndex] = nums[j];
            }
        }
        return uniqueIndex + 1;
    }
};