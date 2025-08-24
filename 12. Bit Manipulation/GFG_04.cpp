// GFG. set the rightmost unset bit -> set 

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
  public:
    int setBit(int n) {
        // Set the rightmost unset bit
        return n | (n + 1);
    }
};

/*
6 -> 0110
  -> 0111

15 -> 01111
   -> 11111
*/