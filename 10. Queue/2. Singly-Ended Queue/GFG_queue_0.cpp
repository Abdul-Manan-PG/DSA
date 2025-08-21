// Geek for geeks: Reverse first k elements from the Queue

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
