// 922. sort array by parity II

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution 
{
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int i = 0, j = 0;
        while (i < nums.size() - 1) {
            if (i % 2 == 0) // if even index
            {
                if (nums[i] % 2 == 0) //  if even value at even index
                {
                    i++;
                    j = i;
                } else // if odd value at even index
                {
                    if (nums[j] % 2 == 0) {
                        swap(nums[i], nums[j]);
                        i++;
                        j = i;
                    } else
                        j++;
                }
            } else // if odd index
            {
                if (nums[i] % 2 != 0) //  if odd value at odd index
                {
                    i++;
                    j = i;
                }
                else // if even value at odd index
                {
                    if (nums[j] % 2 != 0){
                        swap (nums[i], nums[j]);
                        i++;
                        j = i;
                    }
                    else
                    j++;
                }
            }
        }
        return nums;
    }
};