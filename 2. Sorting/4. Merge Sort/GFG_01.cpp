// GFG. Count Inversions
// Problem:
// Given an array of integers. Find the inversion count in the array. Two elements a[i]
// and a[j] form an inversion if a[i] > a[j] and i < j.
//
// Link: `https://www.geeksforgeeks.org/problems/inversion-of-array-1587115620/1`
//
// Constraints (GFG typical):
// - 1 <= N <= 10^5
// - 1 <= arr[i] <= 10^9
//
// Expected Complexity (merge sort based):
// - Time: O(n log n)
// - Space: O(n)


#include <vector>
using namespace std;

long long merge(vector<int>& arr, int left, int mid, int right) {
    vector<int> temp(right - left + 1);
    int i = left, j = mid + 1, k = 0;
    long long inversions = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            inversions += (mid - i + 1); // Count inversions
        }
    }

    // Copy remaining elements
    while (i <= mid) {
        temp[k++] = arr[i++];
    }
    while (j <= right) {
        temp[k++] = arr[j++];
    }

    // Copy back to original array
    for (int idx = left; idx <= right; idx++) {
        arr[idx] = temp[idx - left];
    }

    return inversions;
}

long long mergeSort(vector<int>& arr, int left, int right) {
    long long inversions = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;
        inversions += mergeSort(arr, left, mid);
        inversions += mergeSort(arr, mid + 1, right);
        inversions += merge(arr, left, mid, right);
    }
    return inversions;
}

long long countInversions(vector<int>& arr) {
    return mergeSort(arr, 0, arr.size() - 1);
}

#include <iostream>
int main() {
    vector<int> arr = {3, 1, 2, 4, 5};
    long long inversions = countInversions(arr);
    cout << "Number of inversions: " << inversions << endl;
    // Output: Number of inversions: 2
    return 0;
}

// Solution Complexity:
// - Time: O(n log n)
// - Space: O(n)