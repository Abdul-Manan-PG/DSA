// 417. Pecific Atlantic Water flow

#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if (heights.empty() || heights[0].empty()) return {};

        int rows = heights.size();
        int cols = heights[0].size();

        vector<vector<bool>> canReachPacific(rows, vector<bool>(cols, false));
        vector<vector<bool>> canReachAtlantic(rows, vector<bool>(cols, false));

        // Directions for moving up, down, left, right
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        // Function to perform BFS from a given starting point
        auto bfs = [&](vector<vector<bool>>& canReach, queue<pair<int, int>>& q) {
            while (!q.empty()) {
                auto [x, y] = q.front();
                q.pop();

                for (auto& dir : directions) {
                    int newX = x + dir.first;
                    int newY = y + dir.second;

                    if (newX >= 0 && newX < rows && newY >= 0 && newY < cols && 
                        !canReach[newX][newY] && heights[newX][newY] >= heights[x][y]) {
                        canReach[newX][newY] = true;
                        q.push({newX, newY});
                    }
                }
            }
        };

        // BFS from Pacific border cells
        queue<pair<int, int>> pacificQueue;
        for (int i = 0; i < rows; ++i) {
            pacificQueue.push({i, 0});
            canReachPacific[i][0] = true;
        }
        for (int j = 0; j < cols; ++j) {
            pacificQueue.push({0, j});
            canReachPacific[0][j] = true;
        }
        bfs(canReachPacific, pacificQueue);

        // BFS from Atlantic border cells
        queue<pair<int, int>> atlanticQueue;
        for (int i = 0; i < rows; ++i) {
            atlanticQueue.push({i, cols - 1});
            canReachAtlantic[i][cols - 1] = true;
        }
        for (int j = 0; j < cols; ++j) {
            atlanticQueue.push({rows - 1, j});
            canReachAtlantic[rows - 1][j] = true;
        }
        bfs(canReachAtlantic, atlanticQueue);

        // Collect cells that can reach both oceans
        vector<vector<int>> result;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (canReachPacific[i][j] && canReachAtlantic[i][j]) {
                    result.push_back({i, j});
                }
            }
        }

        return result;
    }
};