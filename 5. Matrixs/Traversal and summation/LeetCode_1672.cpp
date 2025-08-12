// 1672. Richest customer wealth

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int wealth = 0;
        for (int i = 0; i < accounts.size();i++){
            int total = 0;
            for (int j = 0; j < accounts[0].size(); j++){
                total += accounts[i][j];
            }
            if (total > wealth) wealth = total;
        }
        return wealth;
    }
};