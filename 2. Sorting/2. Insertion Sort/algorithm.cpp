#include <iostream>
#include <vector>
#include <string>
using namespace std;

// -----------------Insertion sorting 

void insertionSort(vector<int> &arr, bool desc = false) {
    for (int i = 1; i < arr.size(); i++) {
        int key = arr[i];
        int j = i - 1;
        
        if (desc) {
            while (j >= 0 && arr[j] < key) {
                arr[j + 1] = arr[j];
                j--;
            }
        } else {
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }
        }
        arr[j + 1] = key;
    }
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6};
    
    cout << "Original array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    // Ascending order (default)
    insertionSort(arr);
    cout << "Ascending order: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    // Descending order
    insertionSort(arr, true);
    cout << "Descending order: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    return 0;
}