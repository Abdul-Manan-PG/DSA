// GFG. Implemmentation of Priority Queue using Binary Heap

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// User function Template for C++
// 1. parent(i): Function to return the parent node of node i
// 2. leftChild(i): Function to return index of the left child of node i
// 3. rightChild(i): Function to return index of the right child of node i
// 4. shiftUp(int i): Function to shift up the node in order to maintain the
// heap property
// 5. shiftDown(int i): Function to shift down the node in order to maintain the
// heap property.
// int s=-1, current index value of the array H[].


// Parts of the class priority queue
void shiftDown(int index)
{
    // implementaion
}
int s = 0; // size of queue
int H[]; // array heap 

class Solution
{
public:
    int extractMax()
    {
        if (s == -1)
        {
            // Heap is empty, return some default value (like -1) or throw an exception.
            // Since the problem expects returning the value, we assume heap is non-empty.
            return -1;
        }

        int max = H[0]; // The maximum element is at the root.
        H[0] = H[s];    // Replace the root with the last element.
        s--;            // Reduce the heap size.
        shiftDown(0);   // Shift down the root to restore heap property.
        return max;
    }
};
