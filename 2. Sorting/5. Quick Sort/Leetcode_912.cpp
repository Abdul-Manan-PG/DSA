// 912. Sort an Array
// Problem:
// Given an array of integers nums, sort the array in ascending order and return it.
//
// Link: `https://leetcode.com/problems/sort-an-array/`
//
// Constraints (LeetCode):
// - 1 <= nums.length <= 5 * 10^4
// - -5 * 10^4 <= nums[i] <= 5 * 10^4
//
// Expected Complexity (QuickSort implementation):
// - Average Time: O(n log n), Worst Time: O(n^2) (depending on pivot)
// - Space: O(log n) recursion stack (average), O(n) worst-case

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
        quick_Sort(nums, 0, (nums.size() - 1));
        return nums;
    }
};

// Solution Complexity (this QuickSort):
// - Average Time: O(n log n), Worst Time: O(n^2)
// - Space: O(log n) average (recursion), O(n) worst-case