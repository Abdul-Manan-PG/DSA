#include <iostream>
#include <vector>
#include <string>
using namespace std;

void print(vector<int>& arr, int start, int end){
    while (start <= end){
        cout << arr[start] << " ";
        start++;
    }
    cout << endl;
}

int HoarePartion(vector<int>& arr, int start, int end){
    int x = arr[start];
    int i = start - 1;
    int j = end + 1;
    while (true){
        do
        {
            j--;
        } while (arr[j] > x);
        do
        {
            i++;
        } while (arr[i] < x);
        if (i < j){
            swap(arr[i], arr[j]);
        }
        else
            return j;
    }
}

void QuickSort(vector<int>& arr, int start, int end){
    if (start < end){
        cout << "Arr: ";
        print(arr, start, end);
        int pivot = HoarePartion(arr, start, end);
        cout << "After pivot arr: ";
        print(arr, start, end);
        QuickSort(arr, start, pivot);
        QuickSort(arr, pivot + 1, end);
    }
}

int main(){
    vector<int> arr = {1, 4, 3, 2, 5, 6};
    cout << "Original: ";
    print(arr, 0, arr.size() - 1);
    QuickSort(arr, 0, arr.size() - 1);
    cout << "Result: ";
    print(arr, 0, arr.size() - 1);
    return 0;
}