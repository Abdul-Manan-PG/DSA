// 88. Merge Sorted Array
// Problem:
// You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n,
// representing the number of elements in nums1 and nums2 respectively. Merge nums2 into nums1 as one sorted array.
//
// Link: `https://leetcode.com/problems/merge-sorted-array/`
//
// Constraints (LeetCode):
// - nums1.length == m + n
// - nums2.length == n
// - 0 <= m, n <= 200
// - -10^9 <= nums1[i], nums2[i] <= 10^9
//
// Expected Complexity:
// - In-place from end: Time O(m + n), Space O(1)

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution1 // time complexity O(m * n) space complexity O(1)
{
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (n == 0) {
            return;
        }
        if (m == 0) {
            nums1 = nums2;
            return;
        }
        int i = 0, j = 0;
        while (i < m && j < n){
            if (nums2[j] <= nums1[i]){
                for (int k = m; k > i; k--) {
                    nums1[k] = nums1[k - 1];
                }
                nums1[i] = nums2[j];
                j++;
                m++;
            }
            else
                i++;
        }
        while (j < n){
            nums1[i] = nums2[j];
            i++;
            j++;
        }
    }
};


class Solution // Time complexity O(m + n) and Space complexity O (m + n)
{
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (n == 0) {
            return;
        }
        if (m == 0) {
            nums1 = nums2;
            return;
        }
        vector<int> res(m+n, 0);
        int i = 0, j = 0;
        while (i < m && j < n){
            if (nums2[j] <= nums1[i]){
                res[i + j] = nums2[j];
                j++;
            }
            else{
                res[i + j] = nums1[i];
                i++;
            }
        }
        while (j < n){
            res[m + j] = nums2[j];
            j++;
        }
        while (i < m){
            res[n + i] = nums1[i];
            i++;
        }
        nums1 = res;
    }
};

// Solution1 Complexity (Insertion shifts):
// - Time: O(m * n)
// - Space: O(1)

// Solution Complexity (Extra array merge):
// - Time: O(m + n)
// - Space: O(m + n)