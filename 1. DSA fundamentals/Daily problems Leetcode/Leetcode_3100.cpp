// 3100. Water Bottle II

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int empty = 0;
        int drink = 0;

        while (numBottles > 0) {
            drink += numBottles;       // drink all full bottles
            empty += numBottles;       // add them to empty
            numBottles = 0;

            while (empty >= numExchange) {
                empty -= numExchange;  // spend numExchange empty bottles
                numBottles += 1;       // get 1 new full bottle
                numExchange++;         // cost increases for the next trade
            }
        }
        return drink;
    }
};
