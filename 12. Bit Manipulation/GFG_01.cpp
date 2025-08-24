// GFG. Decimal to Bit

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string decToBinary(int n) {
        // Initialize an empty string to store the binary representation
        string s = "";
        
        // Handle the case when n is 0
        if (n == 0) {
            return "0";
        }

        // Loop until n becomes 0
        while (n > 0) {
            // Prepend the remainder (0 or 1) to the string
            s = to_string(n % 2) + s;
            // Divide n by 2
            n /= 2;
        }
        
        return s;
    }
};
