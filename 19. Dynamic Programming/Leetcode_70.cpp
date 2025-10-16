// 70. Climbing Stairs
// Problem:
// You are climbing a staircase. It takes n steps to reach the top.
// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
//
// Link: `https://leetcode.com/problems/climbing-stairs/`
//
// Constraints (LeetCode):
// - 1 <= n <= 45
//
// Expected Complexity:
// - Memoized recursion: Time O(n), Space O(n)
// - Bottom-up DP: Time O(n), Space O(n)
// - Iterative two-variables: Time O(n), Space O(1)
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution1
{
public:
    int climbStairsHelper(int n, unordered_map<int, int> &memo)
    {
        if (n == 0 || n == 1)
            return 1;
        if (memo.find(n) == memo.end())
        {
            memo[n] = climbStairsHelper(n - 1, memo) + climbStairsHelper(n - 2, memo);
        }
        return memo[n];
    }
    int climbStairs(int n)
    {
        unordered_map<int, int> memo;
        return climbStairsHelper(n, memo);
    }
};

// Solution1 Complexity (Memoization):
// - Time: O(n)
// - Space: O(n)

class Solution2
{
public:
    int climbStairs(int n)
    {
        if (n == 0 || n == 1)
        {
            return 1;
        }

        vector<int> dp(n + 1);
        dp[0] = dp[1] = 1;

        for (int i = 2; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};

// Solution2 Complexity (Bottom-up DP):
// - Time: O(n)
// - Space: O(n)

class Solution3 {
public:
    int climbStairs(int n) {
        if (n == 0 || n == 1) {
            return 1;
        }
        int prev = 1, curr = 1;
        for (int i = 2; i <= n; i++) {
            int temp = curr;
            curr = prev + curr;
            prev = temp;
        }
        return curr;
    }
};

// Solution3 Complexity (Iterative O(1) space):
// - Time: O(n)
// - Space: O(1)