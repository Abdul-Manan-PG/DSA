// 821. Shortest distance to a character

#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // For std::min
using namespace std;


class Solution1
{
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.length();
        vector<int> distance(n, n); // Initialize with a large value (n is safe)
        
        // Forward pass: left to right
        int last_c = -n; // Initialize to a large negative value
        for (int i = 0; i < n; i++) {
            if (s[i] == c) {
                last_c = i;
            }
            distance[i] = i - last_c;
        }
        
        // Backward pass: right to left
        last_c = 2 * n; // Initialize to a large positive value
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == c) {
                last_c = i;
            }
            distance[i] = std::min(distance[i], last_c - i);
        }
        
        return distance;
    }
};

class Solution2 // optimized version
{
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.length();
        vector<int> distance(n, n); // Initialize with a large value (n is safe)
        
        // Forward pass: left to right
        int last_c = -n; // Initialize to a large negative value
        for (int i = 0; i < n; i++) {
            if (s[i] == c) {
                last_c = i;
            }
            distance[i] = i - last_c;
        }
        
        // Backward pass: right to left
        last_c = 2 * n; // Initialize to a large positive value
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == c) {
                last_c = i;
            }
            distance[i] = min(distance[i], last_c - i);
        }
        
        return distance;
    }
};