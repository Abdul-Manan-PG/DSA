// GFG: Reverse First K Elements of Queue
// Problem:
// Given a queue of integers and an integer k, reverse the order of the first k elements of the queue,
// leaving the other elements in the same relative order. The queue should be modified in-place.
//
// Link: `https://www.geeksforgeeks.org/problems/reverse-first-k-elements-of-queue/1`
//
// Constraints (GFG typical):
// - 1 <= N <= 10^5
// - 1 <= k <= N
// - 1 <= queue[i] <= 10^9
//
// Expected Complexity:
// - Stack-based reversal: Time O(n), Space O(k)
// - Recursive reversal: Time O(n), Space O(k) recursion

#include <iostream>
#include <queue>
#include <stack>
#include <string>
using namespace std;


class Solution1 {
  public:
    queue<int> reverseFirstK(queue<int> q, int k) {
        if (k ==0 || k > q.size()) return q;
        // code here
        stack<int> st;
        while (k > 0){
            st.push(q.front());
            q.pop();
            k--;
        }
        queue<int> ret;
        while(!st.empty()){
            ret.push(st.top());
            st.pop();
        }
        while (!q.empty()){
            ret.push(q.front());
            q.pop();
        }
        return ret;
    }
};

// Solution1 Complexity (Stack-based):
// - Time: O(n)
// - Space: O(k)


class Solution2 {
public:
    void reverseFirstKUtil(queue<int>& q, int k) {
        // Base case: if k is 0 or queue is empty
        if (k <= 0 || q.empty()) {
            return;
        }
        
        // Dequeue the front element
        int front = q.front();
        q.pop();
        
        // Recursively call for the next k-1 elements
        reverseFirstKUtil(q, k - 1);
        
        // Enqueue the front element back to the queue
        q.push(front);
    }

    queue<int> reverseFirstK(queue<int> q, int k) {
        // Base case: if k is 0 or greater then size of queue 
        if (k <= 0 || k > q.size()) return q;
        
        // Reverse the first k elements
        reverseFirstKUtil(q, k);
        
        // To maintain the order of the remaining elements, we need to rotate the queue
        int n = q.size();
        for (int i = 0; i < n - k; i++) {
            q.push(q.front());
            q.pop();
        }
        
        return q;
    }
};

// Solution2 Complexity (Recursive):
// - Time: O(n)
// - Space: O(k)
