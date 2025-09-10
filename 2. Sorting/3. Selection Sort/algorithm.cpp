#include <iostream>
#include <vector>
#include <string>
using namespace std;

void selectionSort(vector<int> &arr, bool desc = false) 
{
    for (int i = 0; i < arr.size() - 1; i++)
    {
        int target = i; // Index of min/max element
        for (int j = i + 1; j < arr.size(); j++) 
        {
            if (desc && arr[j] > arr[target]) 
            {
                target = j;
            } 
            else if (!desc && arr[j] < arr[target]) 
            {
                target = j;
            }
        }
        swap(arr[i], arr[target]);
    }
}

int main() {
    vector<int> arr = {64, 25, 12, 22, 11};
    
    cout << "Original array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    // Ascending order (default)
    selectionSort(arr);
    cout << "Ascending order: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    // Descending order
    selectionSort(arr, true);
    cout << "Descending order: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    return 0;
}