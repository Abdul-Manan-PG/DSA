#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void Counting_Sort(vector<int>& arr) {
    int n = arr.size();
    if (n == 0) return;

    int maxVal = *max_element(arr.begin(), arr.end());

    vector<int> counts(maxVal + 1, 0);

    // Step 1: Count occurrences
    for (int num : arr) {
        counts[num]++;
    }

    // Step 2: Prefix sum to get positions
    for (int i = 1; i <= maxVal; i++) {
        counts[i] += counts[i - 1];
    }

    // Step 3: Output array
    vector<int> output(n);
    for (int i = n - 1; i >= 0; i--) {
        output[--counts[arr[i]]] = arr[i];
    }

    // Step 4: Copy back to original array
    arr = output;
}

void printArray (const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {4, 6, 1, 8, 5};
    cout << "Original: ";
    printArray(arr);
    Counting_Sort(arr);
    cout << "\nSorted: ";
    printArray(arr);
    return 0;
}