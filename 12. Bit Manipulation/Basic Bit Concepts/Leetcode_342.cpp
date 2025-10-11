// 342. Power of 4

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    bool isPowerOfFour(int n)
    {
        return n > 0 && (n & (n - 1)) == 0 && (n & 0x55555555);
        // 0x55555555 = (01010101010101010101010101010101) binary
        // for checking that 1 is at odd bit
    }
};

// alternative........
class Solution2
{
public:
    bool isPowerOfFour(int n)
    {
        if (n == 0)
            return false;
        if (n == 1)
            return true;
        if (n % 4 == 0)
        {
            return isPowerOfFour(n / 4);
        }
        return false;
    }
};