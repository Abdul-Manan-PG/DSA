// 2956. Find Common Elements Between Two Arrays
// Problem:
// Given two integer arrays nums1 and nums2, return an array answer of length 2 where:
// answer[0] is the number of elements in nums1 that are present in nums2, and
// answer[1] is the number of elements in nums2 that are present in nums1.
//
// Link: `https://leetcode.com/problems/find-common-elements-between-two-arrays/`
//
// Constraints (LeetCode):
// - 1 <= nums1.length, nums2.length <= 100
// - 1 <= nums1[i], nums2[i] <= 100
//
// Expected Complexity:
// - Using sets/maps: Time O(n + m), Space O(n + m)

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution1 {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> set2(nums2.begin(), nums2.end());

        int answer1 = 0;
        int answer2 = 0;

        // Count how many elements in nums1 exist in nums2
        for (int num : nums1) {
            if (set2.count(num)) {
                answer1++;
            }
        }

        // Count how many elements in nums2 exist in nums1
        for (int num : nums2) {
            if (set1.count(num)) {
                answer2++;
            }
        }

        return {answer1, answer2};
    }
};

// Solution1 Complexity (unordered_set lookup):
// - Time: O(n + m)
// - Space: O(n + m)

class Solution2 {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        // Create frequency maps for both arrays
        unordered_map<int, int> freq1, freq2;

        // Count frequencies in nums1
        for (int num : nums1) {
            freq1[num]++;
        }

        // Count frequencies in nums2
        for (int num : nums2) {
            freq2[num]++;
        }

        int answer1 = 0;
        int answer2 = 0;

        // Count how many elements in nums1 exist in nums2
        for (int num : nums1) {
            if (freq2.count(num)) {
                answer1++;
            }
        }

        // Count how many elements in nums2 exist in nums1
        for (int num : nums2) {
            if (freq1.count(num)) {
                answer2++;
            }
        }

        return {answer1, answer2};
    }
};

// Solution2 Complexity (unordered_map frequency):
// - Time: O(n + m)
// - Space: O(n + m)

class Solution3 {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, bool> existsInNums2;
        for (int num : nums2)
            existsInNums2[num] = true;

        int answer1 = 0;
        for (int num : nums1)
            answer1 += existsInNums2.count(num);

        unordered_map<int, bool> existsInNums1;
        for (int num : nums1)
            existsInNums1[num] = true;

        int answer2 = 0;
        for (int num : nums2)
            answer2 += existsInNums1.count(num);

        return {answer1, answer2};
    }
};

// Solution3 Complexity (unordered_map boolean presence):
// - Time: O(n + m)
// - Space: O(n + m)
