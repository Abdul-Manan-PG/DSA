// 190. Reverse the bit

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int reverseBits(int n) {
        unsigned int ans = 0;
        for (int i = 0; i < 32; i++) {
            ans <<= 1;         // Make room for the next bit
            ans |= (n & 1);    // Add the least significant bit of n
            n >>= 1;           // Move to the next bit
        }
        return ans;
    }
};
