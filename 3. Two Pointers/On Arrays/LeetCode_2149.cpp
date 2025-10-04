// 2149. Rearrange array Elements by signs

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> positives, negatives;
        // Separate positives and negatives while preserving order
        for (int num : nums) {
            if (num > 0) {
                positives.push_back(num);
            } else {
                negatives.push_back(num);
            }
        }
        vector<int> res;
        // Merge them alternately
        for (int i = 0; i < positives.size(); ++i) {
            res.push_back(positives[i]);
            res.push_back(negatives[i]);
        }
        return res;
    }
};