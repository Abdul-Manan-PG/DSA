// 744. Find the smallest letter greater than target

// Description:
// Given a characters array letters that is sorted in non-decreasing order
// and a character target, return the smallest character in the array that is
// lexicographically greater than target. If such a character does not exist,
// return the first character in the array.

#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Solution {
  public:
    char nextGreatestLetter(vector<char> &letters, char target) {
        int n = letters.size();
        int left = 0, right = n - 1;
        char res = letters[0];
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (letters[mid] > target) {
                res = letters[mid];
                right = mid - 1;
            }
            else left = mid + 1;
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<char> letters = {'c', 'f', 'j'};
    char target = 'a';
    cout << sol.nextGreatestLetter(letters, target) << endl; // Output: 'c'
    return 0;
}