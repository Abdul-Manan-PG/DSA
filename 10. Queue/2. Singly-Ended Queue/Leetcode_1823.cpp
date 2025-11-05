// 1823. Winner of the Circular Game

#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

class Solution {
public:
    int findTheWinner(int n, int k) {
        if (n == 1)
            return 1;

        queue<int> q;
        for (int i = 1; i <= n; ++i) {
            q.push(i);
        }

        while (q.size() > 1) {
            // Rotate the queue k-1 times to bring the k-th person to the front
            for (int i = 0; i < k - 1; ++i) {
                int front = q.front();
                q.pop();
                q.push(front);
            }
            // Eliminate the k-th person
            q.pop();
        }

        return q.front();
    }
};

// Solution Complexity:
// - Time: O(n*k) in the worst case due to the rotations

// - Space: O(n) for storing the queue

int main() {
    Solution sol;
    int n = 5, k = 2;
    cout << "The winner is: " << sol.findTheWinner(n, k) << endl; // Output: 3
    return 0;
}