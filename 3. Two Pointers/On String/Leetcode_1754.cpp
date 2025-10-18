// 1754. Largest merge of two strings

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string largestMerge(string word1, string word2) {
        string merge = "";
        int ind1 = 0, ind2 = 0;
        int l1 = word1.size(), l2 = word2.size();
        // int comp = word1.compare(word2);
        while (ind1 < l1 && ind2 < l2) {
            if (word1[ind1] > word2[ind2])
                merge += word1[ind1++];
            else if (word1[ind1] < word2[ind2])
                merge += word2[ind2++];
            else {
                int comp = word1.compare(ind1, string::npos, word2, ind2,
                                         string::npos);
                if (comp >= 0)
                    merge += word1[ind1++];
                else
                    merge += word2[ind2++];
            }
        }
        while (ind1 < l1)
            merge += word1[ind1++];

        while (ind2 < l2)
            merge += word2[ind2++];

        return merge;
    }
};