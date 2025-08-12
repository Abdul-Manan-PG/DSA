// 1380. Lucky numbers in matrix

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> luckyNo;
        vector<int> maxCol(n, 0);
        
        // Find maximum in each column
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < m; i++) {
                if (matrix[i][j] > maxCol[j]) {
                    maxCol[j] = matrix[i][j];
                }
            }
        }
        
        // Find minimum in each row and check if it's also maximum in its column
        for (int i = 0; i < m; i++) {
            int min = matrix[i][0];
            int index = 0;
            for (int j = 1; j < n; j++) {
                if (min > matrix[i][j]) {
                    min = matrix[i][j];
                    index = j;
                }
            }
            if (maxCol[index] == min) {
                luckyNo.push_back(min);
            }
        }
        
        return luckyNo;
    }
};