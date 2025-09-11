// 1974. Minimum Time to type word using Special Typewriter

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int minTimeToType(string word) {
        int sec = 0;
        char initial = 'a';  // starting position
        
        for (char c : word) {
            int diff = abs(c - initial);  // direct distance
            int minSteps = min(diff, 26 - diff);  // choose shortest direction
            sec += minSteps + 1;  // steps + 1 second to type
            initial = c;  // update current position
        }
        
        return sec;
    }
};
