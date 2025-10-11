// 67. Add Binary

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.length() - 1;
        int j = b.length() - 1;
        int carry = 0;
        string ans = "";

        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) sum += a[i--] - '0';  // convert char to int
            if (j >= 0) sum += b[j--] - '0';

            ans += (sum % 2) + '0';   // append result bit
            carry = sum / 2;          // update carry
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
