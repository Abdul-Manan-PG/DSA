// 88. merge sorted arrays

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