#include <iostream>
#include <vector>

using namespace std;

// only for the array whose element are in range of (0 , array.size() - 1) and no duplicate element 

void Cyclic_sort(vector<int>& nums) {
        int i = 0;
        while (i < nums.size()){
            if (nums[i] < nums.size() && nums[i] != i){
                swap(nums[i], nums[nums[i]]);
            }
            else 
                i++;
        }
}

void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {1, 3, 0, 4, 2, 5};
    cout << "Original: ";
    printArray(arr);
    Cyclic_sort(arr);
    cout << "\nSorted: ";
    printArray(arr);
    return 0;
}