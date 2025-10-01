#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int empty = 0;
        int drink = 0;
        while (numBottles > 0){
            drink += numBottles;
            empty += numBottles;
            numBottles = empty / numExchange;
            empty %= numExchange;
        }
        return drink;
    }
};