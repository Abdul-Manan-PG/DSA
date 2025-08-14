// 1207. unique numbers of occurences 

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;


class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> occur;
        for (int num : arr) {
            occur[num]++;
        }

        unordered_set<int> freq;
        for (const auto& pair : occur) {
            if (freq.count(pair.second)) {
                return false;
            }
            freq.insert(pair.second);
        }

        return true;
    }
};