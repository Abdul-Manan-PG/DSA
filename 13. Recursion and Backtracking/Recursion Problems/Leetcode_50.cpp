// 50. Pow(x, n);

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        long long exp = n;   // use long long to safely handle INT_MIN
        if (exp < 0) {
            x = 1 / x;
            exp = -exp;
        }
        return fastPow(x, exp);
    }

private:
    double fastPow(double x, long long n) {
        if (n == 0) return 1.0;
        double half = fastPow(x, n / 2);
        if (n % 2 == 0) {
            return half * half;
        } else {
            return half * half * x;
        }
    }
};
