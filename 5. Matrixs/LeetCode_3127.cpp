// 3127. Make a square with same color

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution1 {
public:
    bool canMakeSquare(vector<vector<char>>& grid) {
        for (int j = 0; j < 2; j++){
            int black_u = 0, black_d = 0;
            if (grid[1][j] == 'B'){
                black_u++;
                black_d++;
            }
            if (grid[1][j+1] == 'B'){
                black_u++;
                black_d++;
            }
            if (grid[0][j] == 'B') black_u++;
            if (grid[0][j + 1] == 'B') black_u++;
            if (grid[2][j] == 'B') black_d++;
            if (grid[2][j + 1] == 'B') black_d++;

            if (black_d <= 1 || black_u <= 1){
                return true;
            }
        }
        for (int j = 0; j < 2; j++){
            int black_u = 0, black_d = 0;
            if (grid[1][j] == 'W'){
                black_u++;
                black_d++;
            }
            if (grid[1][j+1] == 'W'){
                black_u++;
                black_d++;
            }
            if (grid[0][j] == 'W') black_u++;
            if (grid[0][j + 1] == 'W') black_u++;
            if (grid[2][j] == 'W') black_d++;
            if (grid[2][j + 1] == 'W') black_d++;

            if (black_d <= 1 || black_u <= 1){
                return true;
            }
        }
        return false;
    }
};

