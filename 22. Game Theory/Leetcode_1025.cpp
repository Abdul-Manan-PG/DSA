// 1025. Divisor game

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool divisorGame(int n) {
        if (n % 2 == 0){
            return true;
        }
        else
            return false;
    }
};