// 3071. Minimum operations  to write Y on the Grid

#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;

class Solution {
public:
    int minimumOperationsToWriteY(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // d0, d1, d2 → counts of 0/1/2 inside Y
        // n0, n1, n2 → counts of 0/1/2 outside Y
        int d0 = 0, d1 = 0, d2 = 0;
        int n0 = 0, n1 = 0, n2 = 0;

        // --- FIXED: Correct condition for Y shape ---
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                bool isY = (i < m / 2 && (i == j || i + j == n - 1)) || (i >= m / 2 && j == n / 2);

                if (isY) {
                    if (grid[i][j] == 0) d0++;
                    else if (grid[i][j] == 1) d1++;
                    else d2++;
                } else {
                    if (grid[i][j] == 0) n0++;
                    else if (grid[i][j] == 1) n1++;
                    else n2++;
                }
            }
        }

        // --- FIXED: Compute total Y/non-Y cells ---
        int totalY = d0 + d1 + d2;
        int totalN = n0 + n1 + n2;

        // --- FIXED: Try all possible color combinations ---
        int minOps = INT_MAX;
        for (int cY = 0; cY < 3; cY++) {
            for (int cN = 0; cN < 3; cN++) {
                if (cY == cN) continue;

                int sameY = (cY == 0 ? d0 : (cY == 1 ? d1 : d2));
                int sameN = (cN == 0 ? n0 : (cN == 1 ? n1 : n2));

                int operations = (totalY - sameY) + (totalN - sameN);
                minOps = min(minOps, operations);
            }
        }

        return minOps;
    }
};
