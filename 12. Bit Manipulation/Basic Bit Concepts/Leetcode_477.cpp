// 477. Total hamming distance

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int total = 0;
        int n = nums.size();

        for (int bit = 0; bit < 32; bit++) {
            int ones = 0;
            for (int num : nums) {
                if (num & (1 << bit)) ones++;
            }
            total += ones * (n - ones);
        }

        return total;
    }
};
