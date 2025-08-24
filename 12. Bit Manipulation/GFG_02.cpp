// GFG. bit manipulation

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
  public:
    void bitManipulation(int num, int i) {
        // Get the ith bit (1-based index)
        int ith_bit = (num >> (i - 1)) & 1;
        
        // Set the ith bit
        int set_mask = 1 << (i - 1);
        int set_num = num | set_mask;
        
        // Clear the ith bit
        int clear_mask = ~(1 << (i - 1));
        int clear_num = num & clear_mask;
        
        // Print the results as space separated values
        cout << ith_bit << " " << set_num << " " << clear_num;
    }
};