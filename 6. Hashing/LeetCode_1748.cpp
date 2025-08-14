// 1748. Sum of unique elements

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        int sum = 0;
        for (auto& [num, count] : freq) {
            if (count == 1) {
                sum += num;
            }
        }
        return sum;
    }
};
