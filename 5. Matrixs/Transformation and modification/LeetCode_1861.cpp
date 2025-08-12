// 1861. Rotating the box

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m = boxGrid.size();    // Number of rows in the original box
        int n = boxGrid[0].size(); // Number of columns in the original box
        vector<vector<char>> box(n, vector<char>(m, '.')); // Initialize the rotated box

        // Rotate the box 90 degrees clockwise
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                box[j][m - 1 - i] = boxGrid[i][j];
            }
        }

        // Apply gravity to each column in the rotated box
        for (int j = 0; j < m; j++) { // Iterate over each column in the rotated box
            int bottom = n - 1; // Start from the bottom of the column
            for (int i = n - 1; i >= 0; i--) { // Iterate from bottom to top of the column
                if (box[i][j] == '#') {
                    // Move the stone to the current bottom position
                    box[i][j] = '.';
                    box[bottom][j] = '#';
                    bottom--;
                } else if (box[i][j] == '*') {
                    // Obstacle found, reset bottom to above the obstacle
                    bottom = i - 1;
                }
            }
        }

        return box;
    }
};