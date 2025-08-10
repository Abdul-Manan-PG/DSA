// 73. Set matrix zero's

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> zeroRows(rows, 0);
        vector<int> zeroCols(cols, 0);
        
        // First pass: record the rows and columns that need to be zeroed
        for (int a = 0; a < rows; a++) {
            for (int b = 0; b < cols; b++) {
                if (matrix[a][b] == 0) {
                    zeroRows[a] = 1; // Mark the row
                    zeroCols[b] = 1; // Mark the column
                }
            }
        }
        
        // Second pass: set the marked rows and columns to zero
        for (int a = 0; a < rows; a++) {
            for (int b = 0; b < cols; b++) {
                if (zeroRows[a] == 1 || zeroCols[b] == 1) {
                    matrix[a][b] = 0;
                }
            }
        }
    }
};
