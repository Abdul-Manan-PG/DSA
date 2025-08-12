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

class Solution2 {
public:
    bool canMakeSquare(vector<vector<char>>& grid) {
        vector<vector<int>> gridno(3, vector<int>(2, 0));
        for(int i = 0; i < 3; i++){
            for (int j = 0; j < 2; j++){
                if (grid[i][j] == grid[i][j+1]){
                    if (grid[i][j] == 'W') gridno[i][j] = 1;
                    else gridno[i][j] = -1;
                }
                else gridno[i][j] = 0;
            }
        }
        for (int i = 0; i < 2; i++){
            for (int j = 0; j < 2; j++){
                if (gridno[i][j] + gridno[i+1][j] != 0){
                    return true;
                }
            }
        }
        return false;
    }
};