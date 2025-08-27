// 338. Counting bits

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution1 // Dynamic Programming with Bit Manipulation (Most Efficient)
{
public:
    vector<int> countBits(int n) {
        vector<int> dp(n + 1, 0);
        
        for (int i = 1; i <= n; i++) {
            // Number of 1's in i is equal to number of 1's in i/2 
            // plus the least significant bit
            dp[i] = dp[i >> 1] + (i & 1);
        }
        
        return dp;
    }
};

class Solution2 // Dynamic Programming with Offset
{
public:
    vector<int> countBits(int n) {
        vector<int> dp(n + 1, 0);
        
        for (int i = 1; i <= n; i++) {
            // For numbers that are powers of 2, they have exactly one 1
            // For other numbers, use previously computed results
            dp[i] = dp[i & (i - 1)] + 1;
        }
        
        return dp;
    }
};

class Solution3 // Brute Force 
{
public:
    vector<int> countBits(int n) {
        vector<int> result(n + 1);
        
        for (int i = 0; i <= n; i++) {
            // can also use built in function for counting 1's
            int count = 0;
            int num = i;
            while (num > 0) {
                count += num & 1;
                num >>= 1;
            }
            
            result[i] = count;
        }

        
        return result;
    }
};