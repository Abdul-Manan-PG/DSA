// 191. Number of bits

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution1 // Check every bit individualy
{
public:
    int hammingWeight(int num) {
        if (num == 0) return 0;
        int bits = 0;
        while (num) {
            if (num & 1) bits++;  // Check the least significant bit
            num >>= 1;            // Shift right to check next bit
        }
        return bits;
    }
};

class Solution2 // Using Brian Kernighan's Algorithm (more efficient)
{
public:
    int hammingWeight(int num) {
        int count = 0;
        while (num) {
            num &= (num - 1);  // This clears the rightmost set bit
            count++;
        }
        return count;
    }
};

class Solution // using built in function
{
public:
    int hammingWeight(int num) {
        return __builtin_popcount(num);
    }
};