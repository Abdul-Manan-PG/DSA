// Problem no 912: Sort an array

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int partition(vector<int>& arr, int start, int end) {
        int index = start - 1;
        for (int j = start; j < end; j++) {
            if (arr[j] <= arr[end]) {
                index++;
                swap(arr[j], arr[index]);
            }
        }
        index++;
        swap(arr[end], arr[index]);
        return index;
    }

    void quick_Sort(vector<int>& arr, int start, int end) {
        if (start < end) {
            int pivot = partition(arr, start, end);
            quick_Sort(arr, start, pivot - 1);
            quick_Sort(arr, pivot + 1, end);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        return quick_sort(nums, 0, nums.size() - 1);
    }
};