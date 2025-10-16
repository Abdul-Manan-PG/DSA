// 231. Power of Two
// Problem:
// Given an integer n, return true if it is a power of two. Otherwise, return false.
// An integer n is a power of two if there exists an integer x such that n == 2^x.
//
// Link: `https://leetcode.com/problems/power-of-two/`
//
// Constraints (LeetCode):
// - -2^31 <= n <= 2^31 - 1
//
// Expected Complexity:
// - Bitwise check: Time O(1), Space O(1)
// - Recursive division by 2: Time O(log n), Space O(log n)

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

// Solution1 Complexity (Bitwise):
// - Time: O(1)
// - Space: O(1)

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

// Solution2 Complexity (Recursive division):
// - Time: O(log n)
// - Space: O(log n)