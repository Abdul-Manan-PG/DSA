// 1290. Convert binary Number in a Linked List to Integer

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