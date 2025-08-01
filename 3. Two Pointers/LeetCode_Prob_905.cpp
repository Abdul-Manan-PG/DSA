#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution // time complexity O(n)
{
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int i = 0, j = 0;
        while (j < nums.size()){
            if (nums[j] % 2 == 0){
                swap(nums[j], nums[i]);
                i++;
                j++;
            }
            else
            j++;
        }
        return nums;
    }
};