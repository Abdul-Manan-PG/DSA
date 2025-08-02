// 27. remove Element

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.empty())
            return 0;
        int i = 0, n = nums.size();
        while (i < n) {
            if (nums[i] == val) {
                swap(nums[i], nums[n - 1]);
                n--;
            } else
                i++;
        }
        return n;
    }
};