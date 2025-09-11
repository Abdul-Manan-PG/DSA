// 1323. Maximum 69 number

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int maximum69Number (int num) {
        string s = to_string(num); // convert number to string for easy digit manipulation
        for (char &c : s) {
            if (c == '6') { // change the first 6 to 9
                c = '9';
                break; // only one change allowed
            }
        }
        return stoi(s); // convert back to int
    }
};