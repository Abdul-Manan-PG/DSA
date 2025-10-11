// 461. Hamming distance

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    int hammingDistance(int x, int y)
    {
        int n = x ^ y; // XOR to find differing bits
        int count = 0;
        while (n > 0)
        {
            count += (n & 1); // add 1 if last bit is set
            n >>= 1;          // move to next bit
        }
        return count;
    }
};

// Hamming distance is the numbers of bits which are different at positions of bits