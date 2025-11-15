// GFG. Sort the stack using recursion

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
  public:
    void sortStack(stack<int> &st) {
        // code here
        if (st.empty()) return;
        int x = st.top();
        st.pop();
        if (!st.empty()) sortStack(st);
        if (!st.empty() && st.top() > x){
            stack<int> temp;
            while (!st.empty() && st.top() > x){
                temp.push(st.top());
                st.pop();
            }
            st.push(x);
            while (!temp.empty()){
                st.push(temp.top());
                temp.pop();
            }
        }
        else{
            st.push(x);
        }
    }
};
