// 476. Number Compliment

#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Solution {
public:
    int findComplement(int num) {
        if (num == 0) return 1;
        int n = 0;
        int temp = num;
        while (temp) {
            n++;
            temp >>= 1;
        }
        int mask = (1LL << n) - 1;
        return num ^ mask;
    }
};