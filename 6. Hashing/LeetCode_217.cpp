// 217. Contains Duplicate

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution1 {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> n;
        for (int i = 0; i < nums.size(); i++){
            if (n.find(nums[i]) == n.end()){
                n.emplace(nums[i], 1);
            }
            else
                return true;
        }
        return false;
    }
};

class Solution2 {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        for (int num : nums) {
            if (seen.find(num) != seen.end()) {
                return true;
            }
            seen.insert(num);
        }
        return false;
    }
};