// 109. Convert Sorted List to Binary Search Tree
// Problem:
// Given the head of a singly linked list where elements are sorted in ascending order,
// convert it to a height-balanced BST.
//
// Link: `https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/`
//
// Constraints (LeetCode):
// - The number of nodes is in the range [0, 2 * 10^4]
// - -10^5 <= Node.val <= 10^5
//
// Expected Complexity:
// - Array conversion + build: Time O(n), Space O(n) for array
// - Fast/slow + recursion: Time O(n log n) naive, optimized O(n) with in-order traversal

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Solution1 Complexity (Array + build):
// - Time: O(n)
// - Space: O(n)

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Solution2 Complexity (Two-pointer middle + recursion):
// - Time: O(n log n) in general; with careful in-order pointer walk can be O(n)
// - Space: O(log n) recursion

class Solution1
{
    TreeNode *buildBST(vector<int> &nums, int left, int right)
    {
        if (left > right)
            return nullptr;

        int mid = left + (right - left) / 2; // middle element
        TreeNode *root = new TreeNode(nums[mid]);

        root->left = buildBST(nums, left, mid - 1);
        root->right = buildBST(nums, mid + 1, right);

        return root;
    }
    vector<int> LL_to_array(ListNode *head)
    {
        vector<int> ans;
        while (head)
        {
            ans.push_back(head->val);
            head = head->next;
        }
        return ans;
    }
public:
    TreeNode *sortedListToBST(ListNode *head)
    {
        vector<int> nums = LL_to_array(head);
        return buildBST(nums, 0, nums.size() - 1);
    }
};


class Solution2 // optimized version
{
    ListNode *findMiddle(ListNode *head, ListNode *tail)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != tail && fast->next != tail)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow; // middle node
    }

    TreeNode *buildBST(ListNode *head, ListNode *tail)
    {
        if (head == tail)
            return nullptr;

        ListNode *mid = findMiddle(head, tail);
        TreeNode *root = new TreeNode(mid->val);

        root->left = buildBST(head, mid);
        root->right = buildBST(mid->next, tail);

        return root;
    }

public:
    TreeNode *sortedListToBST(ListNode *head)
    {
        return buildBST(head, nullptr);
    }
};