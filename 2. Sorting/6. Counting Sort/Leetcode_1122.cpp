// 1122. Relative Sort Array

#include <iostream>
#include <vector>
#include <string>
using namespace std;

#include <vector>
#include <algorithm>
using namespace std;

class Solution1 
{
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int maxVal = *max_element(arr1.begin(), arr1.end());
        vector<int> count(maxVal + 1, 0);

        // Count frequency of each number in arr1
        for (int num : arr1) {
            count[num]++;
        }

        vector<int> result;

        // Place elements from arr2 first, in order
        for (int num : arr2) {
            while (count[num] > 0) {
                result.push_back(num);
                count[num]--;
            }
        }

        // Place remaining elements in ascending order
        for (int i = 0; i <= maxVal; i++) {
            while (count[i] > 0) {
                result.push_back(i);
                count[i]--;
            }
        }

        return result;
    }
};
