// 1260. Shift the 2D array

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int elements = m * n;

        // Normalize k to be within the bounds of the number of elements
        k = k % elements;
        if (k == 0) return grid; // No shift needed

        // Create a new grid to store the shifted values
        vector<vector<int>> newGrid(m, vector<int>(n));

        // Fill the new grid with shifted values
        for (int i = 0; i < elements; ++i) {
            int newPos = (i + k) % elements;
            newGrid[newPos / n][newPos % n] = grid[i / n][i % n];
        }

        return newGrid;
    }
};

