// 1290. Convert Binary Number in a Linked List to Integer
// Problem:
// Given head which is a reference node to a singly-linked list. The value of each node in the linked list is either 0 or 1.
// The linked list holds the binary representation of a number. Return the decimal value of the number in the linked list.
//
// Link: `https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/`
//
// Constraints (LeetCode):
// - The number of nodes in the linked list is in the range [1, 30].
// - Node.val is either 0 or 1.
//
// Expected Complexity:
// - Time: O(n)
// - Space: O(1)

#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Solution Complexity:
// - Time: O(n)
// - Space: O(1)

class Solution
{
public:
    int getDecimalValue(ListNode *head)
    {
        string s = "";
        while (head != nullptr)
        {
            s += to_string(head->val);
            head = head->next;
        }
        if (s == "" || s == "0")
            return 0;
        int result = 0;
        int twos = 1;
        for (int i = s.length() - 1; i >= 0; i--)
        {
            if (s[i] == '1')
            {
                result += twos;
            }
            twos *= 2;
        }
        return result;
    }
};