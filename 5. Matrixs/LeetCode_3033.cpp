// 3033. Modify the matrix

#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;

class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (m == 0) return matrix;
        int n = matrix[0].size();
        vector<int> colMax(n, INT_MIN); // Initialize to smallest possible integer

        // Find the maximum in each column
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < m; i++) {
                if (matrix[i][j] > colMax[j]) {
                    colMax[j] = matrix[i][j];
                }
            }
        }

        // Replace -1 with the maximum of its column
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == -1) {
                    matrix[i][j] = colMax[j];
                }
            }
        }

        return matrix;
    }
};