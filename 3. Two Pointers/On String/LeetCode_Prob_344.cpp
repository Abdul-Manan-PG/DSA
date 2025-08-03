// 344. Reverse the string

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution // Time complexity is O(n)
{
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        for (int i = 0; i <= (n - 1) / 2; i++){
            swap(s[i], s[n - i - 1]);
        }
    }
};
