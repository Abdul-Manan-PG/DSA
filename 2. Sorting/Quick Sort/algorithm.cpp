#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int>& arr, int start, int end){
    int index = start - 1;
    for (int j = start; j < end; j++){
        if (arr[j] <= arr[end]){
            index++;
            swap(arr[j], arr[index]);
        }
    }
    index++;
    swap(arr[end], arr[index]);
    return index;
}

void quick_Sort(vector<int>& arr, int start, int end){
    if (start < end){
        int pivot = partition(arr, start, end);
        quick_Sort(arr, start, pivot - 1);
        quick_Sort(arr, pivot+1, end);
    }
}

void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {4, 6, 1, 8, 5};
    cout << "Original: ";
    printArray(arr);
    quick_Sort(arr, 0, arr.size() - 1);
    cout << "\nSorted: ";
    printArray(arr);
    return 0;
}