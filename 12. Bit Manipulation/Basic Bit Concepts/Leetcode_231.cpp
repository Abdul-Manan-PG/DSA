// 231. Power of Two

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution1
{
public:
    bool isPowerOfTwo(int n)
    {
        return n > 0 && (n & (n - 1)) == 0;
    }
};

class Solution2
{
public:
    bool isPowerOfTwo(int n)
    {
        if (n == 0)
            return false;
        if (n == 1)
            return true;
        if (n % 2 == 0)
        {
            return isPowerOfTwo(n / 2);
        }
        return false;
    }
};