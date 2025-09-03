// 509. Fabonacci Series 

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int fib(int n) {
        if (n == 1 || n == 2) return 1;
        if (n > 2) {
            return fib(n - 2) + fib(n - 1);
        }
        return 0;
    }
};