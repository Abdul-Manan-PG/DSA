// GFG. Ith index of bit is set or not

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
  public:
    bool checkKthBit(int n, int k) {
        int ith_bit = (n >> k) & 1;
        return ith_bit == 1;
    }
};