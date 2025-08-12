// 48. Rotate image

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i = 0; i < m; i++){
            for (int j = i + 1; j < n; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n / 2; j++){
                swap(matrix[i][j], matrix[i][n-1-j]);
            }
        }
    }
};