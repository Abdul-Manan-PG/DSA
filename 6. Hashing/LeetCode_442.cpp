// 442. Find all duplicates

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }
        vector<int> duplicates;
        for (auto& [num, count] : freq) {
            if (count > 1) {
                duplicates.push_back(num);
            }
        }
        return duplicates;
    }
};