#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int i = 0;
        while (i < nums.size()){
            if (nums[i] < nums.size() && nums[i] != i){
                swap(nums[i], nums[nums[i]]);
            }
            else 
                i++;
        }
        for (i = 0; i < nums.size(); i++){
            if (i != nums[i])
                return i;
        }
        return nums.size();
    }
};

int main(){
    vector<int> arr = {1, 2, 5, 4, 3, 0};
    Solution s;
    cout << "Missing number is " << s.missingNumber(arr) << endl;
    return 0;
}