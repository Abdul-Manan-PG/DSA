// 2946. Matrix Similarity after Cyclic shifts

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        k %= n;
        if (n <= 1) return true;
        for (int i= 0; i < m; i++){
            if (i % 2 == 0){
                for (int j = 0; j < n; j++){
                    int newPos = (j + k) % n;
                    if (mat[i][newPos] != mat[i][j]){
                        return false;
                    }
                }
            }
            else{
                for (int j = 0; j < n; j++){
                    int newPos = (j - k);
                    if (newPos < 0) newPos += n;
                    if (mat[i][newPos] != mat[i][j]){
                        return false;
                    }
                }
            }
        }

        return true;
    }
};