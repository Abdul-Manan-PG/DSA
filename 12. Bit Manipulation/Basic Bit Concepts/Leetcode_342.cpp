// 342. Power of Four
// Problem:
// Given an integer n, return true if it is a power of four. Otherwise, return false.
// An integer n is a power of four if there exists an integer x such that n == 4^x.
//
// Link: `https://leetcode.com/problems/power-of-four/`
//
// Constraints (LeetCode):
// - -2^31 <= n <= 2^31 - 1
//
// Expected Complexity:
// - Bitwise check: Time O(1), Space O(1)
// - Recursive division by 4: Time O(log_4 n) ~ O(log n), Space O(log n) recursion

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

// Solution Complexity (Bitwise):
// - Time: O(1)
// - Space: O(1)

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

// Solution Complexity (Recursive division):
// - Time: O(log n)
// - Space: O(log n) due to recursion depth