// 2319. Check if Matrix is X Matrix

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool checkXMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j || (i + j == n - 1)) { // Check diagonals
                    if (grid[i][j] == 0) {
                        return false;
                    }
                } else { // Check non-diagonals
                    if (grid[i][j] != 0) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};