// 315. Count of Smaller Numbers After Self
// Problem:
// Given an integer array nums, return a new counts array. counts[i] is the number
// of smaller elements to the right of nums[i].
//
// Link: `https://leetcode.com/problems/count-of-smaller-numbers-after-self/`
//
// Constraints (LeetCode):
// - 1 <= nums.length <= 10^5
// - -10^4 <= nums[i] <= 10^4
//
// Expected Complexity (merge sort with indices):
// - Time: O(n log n)
// - Space: O(n)

#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& nums, int left, int mid, int right, vector<int>& count, vector<int>& index, vector<int>& tempIndex) {
    int i = left, j = mid + 1, k = left;
    int rightCount = 0; // Number of elements from the right subarray that are smaller than elements in the left subarray

    while (i <= mid && j <= right) {
        if (nums[index[i]] <= nums[index[j]]) {
        count[index[i]] += rightCount;
            tempIndex[k++] = index[i++];
        } else {
            rightCount++;
            tempIndex[k++] = index[j++];
        }
    }

    // Remaining elements in the left subarray
    while (i <= mid) {
        count[index[i]] += rightCount;
        tempIndex[k++] = index[i++];
    }

    // Remaining elements in the right subarray
    while (j <= right) {
        tempIndex[k++] = index[j++];
    }
    // Copy the merged indices back to the original index array
    for (int l = left; l <= right; l++) {
        index[l] = tempIndex[l];
    }
}


void mergeSort(vector<int>& nums, int left, int right, vector<int>& count, vector<int>& index, vector<int>& tempIndex) {
    if (left >= right) {
        return;
    }
    int mid = left + (right - left) / 2;
    mergeSort(nums, left, mid, count, index, tempIndex);
    mergeSort(nums, mid + 1, right, count, index, tempIndex);
    merge(nums, left, mid, right, count, index, tempIndex);
}

vector<int> countSmaller(vector<int>& nums) {
    int n = nums.size();
    vector<int> count(n, 0);
    vector<int> index(n), tempIndex(n);
    // Initialize the index array
    for (int i = 0; i < n; i++) {
        index[i] = i;
    }
    mergeSort(nums, 0, n - 1, count, index, tempIndex);
    return count;
}

// Solution Complexity:
// - Time: O(n log n)
// - Space: O(n)