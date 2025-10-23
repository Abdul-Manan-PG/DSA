// 374. Guess the numbers Higher or Lower

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Forward declaration of the guess API.
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int low = 1;
        int high = n;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int res = guess(mid);
            if (res == 0) {
                return mid;
            } else if (res == -1) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return -1; // This line should never be reached as the number is always in the range.
    }
};
