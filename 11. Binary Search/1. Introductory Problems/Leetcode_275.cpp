// 275. H-index II

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size(); // Get the size of the citations array
        int low = 0, high = n; // Initialize the binary search range
        while (low < high) { // Perform binary search
            int mid = low + (high - low) / 2; // Calculate the middle index
            if (citations[n - mid - 1] >= mid + 1) { 
                low = mid + 1; // If it does, move the lower bound up
            } else {
                high = mid; // Otherwise, move the upper bound down
            }
        }
        return low; // The lower bound will be the h-index
    }
};

int main() {
    Solution sol;
    vector<int> citations = {0, 1, 3, 5, 6};
    cout << "H-Index: " << sol.hIndex(citations) << endl; // Output: H-Index: 3
    return 0;
}