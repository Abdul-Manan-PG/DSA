// 1914. Cyclically rotating the grid

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    void solve(vector<vector<int>>& arr, int index, int k,
               vector<vector<int>>& ans) {
        int a = arr.size() - index - 1;
        int b = arr[0].size() - index - 1;

        vector<int> temp;

        for (int j = index; j <= b; j++)
            temp.push_back(arr[index][j]);

        for (int i = index + 1; i <= a; i++)
            temp.push_back(arr[i][b]);

        for (int j = b - 1; j >= index; j--)
            temp.push_back(arr[a][j]);

        for (int i = a - 1; i > index; i--)
            temp.push_back(arr[i][index]);

        int count = temp.size();
        k = k % count;
        int x = k;
        for (int j = index; j <= b; j++) {
            ans[index][j] = temp[x];
            x == count - 1 ? x = 0 : x++;
        }
        for (int i = index + 1; i <= a; i++) {
            ans[i][b] = temp[x];
            x == count - 1 ? x = 0 : x++;
        }
        for (int j = b - 1; j >= index; j--) {
            ans[a][j] = temp[x];
            x == count - 1 ? x = 0 : x++;
        }
        for (int i = a - 1; i > index; i--) {
            ans[i][index] = temp[x];
            x == count - 1 ? x = 0 : x++;
        }
    }
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        vector<vector<int>> ans(grid.size(), vector<int>(grid[0].size()));
        int count = min(grid[0].size(), grid.size()) / 2;

        for (int i = 0; i < count; i++)
            solve(grid, i, k, ans);

        return ans;
    }
};

