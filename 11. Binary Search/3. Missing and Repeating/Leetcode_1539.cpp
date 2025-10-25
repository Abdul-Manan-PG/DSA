// 1539. Kth Missing Positive Number

// https://leetcode.com/problems/kth-missing-positive-number/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    int findKthPositive(vector<int> &arr, int k)
    {
        int low = 0, high = arr.size() - 1;

        // Binary search
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int missing = arr[mid] - (mid + 1);

            if (missing < k)
                low = mid + 1;
            else
                high = mid - 1;
        }

        // After the loop, 'low' is the count of non-missing numbers before answer
        return low + k;
    }
};

int main()
{
    Solution solution;
    vector<int> arr = {2, 3, 4, 7, 11};
    int k = 5;
    int result = solution.findKthPositive(arr, k);
    cout << "The " << k << "th missing positive number is: " << result << endl; // Output: 9
    return 0;
}