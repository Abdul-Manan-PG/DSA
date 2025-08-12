// 2643. Row with maximum ones

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int n = mat[0].size();
        vector<int> vec(2, 0);
        for (int i = 0; i < mat.size(); i++) {
            int ones = 0;
            for (int j = 0; j < n; j++) {
                ones += mat[i][j];
            }
            if (ones > vec[1]) {
                vec[0] = i;
                vec[1] = ones;
            }
            if (vec[1] == n) break; // Early exit if the maximum possible is found
        }
        return vec;
    }
};