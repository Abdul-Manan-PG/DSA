// 867. Transpose of matrix 

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> newMatrix(n, vector<int>(m));
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                newMatrix[j][i] = matrix[i][j];
            }
        }
        return newMatrix;
    }
};