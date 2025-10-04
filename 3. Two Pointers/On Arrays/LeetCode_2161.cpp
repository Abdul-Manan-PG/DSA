// 2161. Partition array According to Given pivot

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> small;
        vector<int> large;
        int count = 0;
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] > pivot){
                large.push_back(nums[i]);
            }
            else if (nums[i] < pivot){
                small.push_back(nums[i]);
            }
            else
                count++;
        }
        vector<int> res;
        for (int i : small){
            res.push_back(i);
        }
        for (int i = 0; i < count; i++){
            res.push_back(pivot);
        }
        for (int i : large){
            res.push_back(i);
        }
        return res;
    }
};